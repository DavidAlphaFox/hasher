%%% @author David.Gao  <david.alpha.fox@gmail.com>
%%%
%%% @copyright 2013 
%%% @version 0.1.0

-module(hasher).
-version(0.1).

-export([murmur2/1,fnv1_64/1,fnv1a_64/1,fnv1_32/1,fnv1a_32/1]).

-on_load(init/0).

-define(nif_stub, nif_stub_error(?LINE)).

-type hash_input() :: binary() | atom() | number() | list().
-type hash_digest() :: non_neg_integer().


nif_stub_error(Line) ->
    erlang:nif_error({nif_not_loaded, module, ?MODULE, line, Line}).


%%%=============================================================================
%%% Initializer
%%%=============================================================================


-spec init() -> ok | {error, any()}.

init() ->
    PrivDir = case code:priv_dir(?MODULE) of
                  {error, bad_name} ->
                      EbinDir = filename:dirname(code:which(?MODULE)),
                      AppPath = filename:dirname(EbinDir),
                      filename:join(AppPath, "priv");
                  Path ->
                      Path
              end,
    erlang:load_nif(filename:join(PrivDir, hasher_nif), 0).


%%%=============================================================================
%%% Nif functions
%%%=============================================================================
hasher_murmur2(_Data) ->
  ?nif_stub.
hasher_fnv1_64(_Data) ->
  ?nif_stub.
hasher_fnv1a_64(_Data) ->
  ?nif_stub.
hasher_fnv1_32(_Data) ->
  ?nif_stub.
hasher_fnv1a_32(_Data) ->
  ?nif_stub.


%%%=============================================================================
%%% Exports
%%%=============================================================================

-spec murmur2(Data::hash_input()) -> hash_digest().
murmur2(Data)->
	hasher_murmur2(supported_to_binary(Data)).

-spec fnv1_64(Data::hash_input()) -> hash_digest().
fnv1_64(Data)->
	hasher_fnv1_64(supported_to_binary(Data)).

-spec fnv1a_64(Data::hash_input()) -> hash_digest().
fnv1a_64(Data)->
	hasher_fnv1a_64(supported_to_binary(Data)).

-spec fnv1_32(Data::hash_input()) -> hash_digest().
fnv1_32(Data)->
	hasher_fnv1_32(supported_to_binary(Data)).

-spec fnv1a_32(Data::hash_input()) -> hash_digest().
fnv1a_32(Data)->
	hasher_fnv1a_32(supported_to_binary(Data)).

%%%=============================================================================
%%% Helpers
%%%=============================================================================

supported_to_binary(Data) when is_binary(Data) ->
  Data;
supported_to_binary(Data) when is_list(Data) ->
  list_to_binary(Data);
supported_to_binary(Data) when is_atom(Data) ->
  term_to_binary(Data);
supported_to_binary(Data) when is_integer(Data) ->
  list_to_binary(integer_to_list(Data));
supported_to_binary(Data) when is_float(Data) ->
  <<Data/float>>.


%%%=============================================================================
%%% Tests
%%%=============================================================================

-ifdef(TEST).

-include_lib("eunit/include/eunit.hrl").

-endif.
