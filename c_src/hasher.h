
#pragma once

#if defined (__cplusplus)
extern "C" {
#endif

	 uint32_t hash_murmur2(const unsigned char *data, size_t length);
	 uint64_t hash_fnv1_64(const unsigned char *key, size_t key_length);
	 uint64_t hash_fnv1a_64(const unsigned char *key, size_t key_length);
	 uint32_t hash_fnv1_32(const unsigned char *key, size_t key_length);
	 uint32_t hash_fnv1a_32(const unsigned char *key, size_t key_length);


#if defined (__cplusplus)
}
#endif
