#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "openssl/evp.h"

void digest_message(const char *message, size_t message_len, unsigned char **digest, unsigned int *digest_len)
{
	EVP_MD_CTX *mdctx;

	if((mdctx = EVP_MD_CTX_new()) == NULL)
		exit(1);

	if(1 != EVP_DigestInit_ex(mdctx, EVP_sha256(), NULL))
		exit(1);

	if(1 != EVP_DigestUpdate(mdctx, message, message_len))
		exit(1);

	if((*digest = (unsigned char *)OPENSSL_malloc(EVP_MD_size(EVP_sha256()))) == NULL)
		exit(1);

	if(1 != EVP_DigestFinal_ex(mdctx, *digest, digest_len))
		exit(1);

	EVP_MD_CTX_free(mdctx);
}

std::string sha256(const std::string str)
{
    using namespace std;
    unsigned char *digest = nullptr;
    unsigned int digest_len = 0;
    digest_message(str.data(), str.size(), &digest, &digest_len);

    stringstream ss;
    for(int i = 0; i < digest_len; i++)
    {
        ss << hex << setw(2) << setfill('0') << (int)digest[i];
    }
    return ss.str();
}

int main() {
    std::cout << sha256("Hello, world") << '\n';
}