#include "erl_nif.h"
#include "hasher.h"
#define UNUSED(x) (void)(x)

static ERL_NIF_TERM nif_hasher_murmur2(ErlNifEnv *env, int argc,const ERL_NIF_TERM argv[]);
static ERL_NIF_TERM nif_hasher_fnv1_64(ErlNifEnv *env, int argc,const ERL_NIF_TERM argv[]);
static ERL_NIF_TERM nif_hasher_fnv1a_64(ErlNifEnv *env, int argc,const ERL_NIF_TERM argv[]);
static ERL_NIF_TERM nif_hasher_fnv1_32(ErlNifEnv *env, int argc,const ERL_NIF_TERM argv[]);
static ERL_NIF_TERM nif_hasher_fnv1a_32(ErlNifEnv *env, int argc,const ERL_NIF_TERM argv[]);

static ErlNifFunc nif_funcs[] = {
	 {"hasher_murmur2", 1, nif_hasher_murmur2}
	 {"hasher_fnv1_64", 1, nif_hasher_fnv1_64}
	 {"hasher_fnv1a_64", 1, nif_hasher_fnv1a_64}
	 {"hasher_fnv1_32", 1, nif_hasher_fnv1_32}
	 {"hasher_fnv1a_32", 1, nif_hasher_fnv1a_32}

};


static ERL_NIF_TERM nif_hasher_murmur2(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[]) {
  ErlNifBinary bin;
  uint32_t hash;
  UNUSED(argc);

  if (!enif_inspect_binary(env, argv[0], &bin)) {
    return enif_make_badarg(env);
  }
  hash = hash_murmur2(bin.data,bin.size);
  return enif_make_uint(env, hash);
}

static ERL_NIF_TERM nif_hasher_fnv1_64(ErlNifEnv *env, int argc,const ERL_NIF_TERM argv[]){
	 ErlNifBinary bin;
	 uint64_t hash;
	 UNUSED(argc);

	 if (!enif_inspect_binary(env, argv[0], &bin)) {
		  return enif_make_badarg(env);
	 }
	 hash = hash_fnv1_64(bin.data,bin.size);
	 return enif_make_uint64(env, hash);
}

static ERL_NIF_TERM nif_hasher_fnv1a_64(ErlNifEnv *env, int argc,const ERL_NIF_TERM argv[]){
	 ErlNifBinary bin;
	 uint64_t hash;
	 UNUSED(argc);

	 if (!enif_inspect_binary(env, argv[0], &bin)) {
		  return enif_make_badarg(env);
	 }
	 hash = hash_fnv1a_64(bin.data,bin.size);
	 return enif_make_uint64(env, hash);
}

static ERL_NIF_TERM nif_hasher_fnv1_32(ErlNifEnv *env, int argc,const ERL_NIF_TERM argv[]){
	 ErlNifBinary bin;
	 uint32_t hash;
	 UNUSED(argc);

	 if (!enif_inspect_binary(env, argv[0], &bin)) {
		  return enif_make_badarg(env);
	 }
	 hash = hash_fnv1_32(bin.data,bin.size);
	 return enif_make_uint(env, hash);
}

static ERL_NIF_TERM nif_hasher_fnv1a_32(ErlNifEnv *env, int argc,const ERL_NIF_TERM argv[]){
	 ErlNifBinary bin;
	 uint32_t hash;
	 UNUSED(argc);

	 if (!enif_inspect_binary(env, argv[0], &bin)) {
		  return enif_make_badarg(env);
	 }
	 hash = hash_fnv1a_32(bin.data,bin.size);
	 return enif_make_uint(env, hash);
}


ERL_NIF_INIT(hasher, nif_funcs, NULL, NULL, NULL, NULL);
