#include "erl_nif.h"
#include "hasher.h"
#define UNUSED(x) (void)(x)

static ERL_NIF_TERM nif_hasher_murmur2(ErlNifEnv *env, int argc,const ERL_NIF_TERM argv[]);

static ErlNifFunc nif_funcs[] = {
  {"hasher_murmur2", 1, nif_hasher_murmur2}
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

ERL_NIF_INIT(hasher, nif_funcs, NULL, NULL, NULL, NULL);
