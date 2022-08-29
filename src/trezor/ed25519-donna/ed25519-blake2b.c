#include <stddef.h>

#include <trezor/ed25519-donna/ed25519-blake2b.h>
#include <trezor/ed25519-donna/ed25519-hash-custom-blake2b.h>

#define ED25519_SUFFIX _blake2b

#include "ed25519.c"