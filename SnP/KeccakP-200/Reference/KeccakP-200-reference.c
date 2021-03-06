/*
Implementation by the Keccak, Keyak and Ketje Teams, namely, Guido Bertoni,
Joan Daemen, Michaël Peeters, Gilles Van Assche and Ronny Van Keer, hereby
denoted as "the implementer".

For more information, feedback or questions, please refer to our websites:
http://keccak.noekeon.org/
http://keyak.noekeon.org/
http://ketje.noekeon.org/

To the extent possible under law, the implementer has waived all copyright
and related or neighboring rights to the source code in this file.
http://creativecommons.org/publicdomain/zero/1.0/
*/

#include "brg_endian.h"

typedef unsigned char UINT8;
typedef UINT8 tKeccakLane;

#define nrRounds 18

void KeccakF200Round(tKeccakLane *state, unsigned int indexRound); // From KeccakF-200/Reference

void KeccakP200_StatePermute(void *state, unsigned int nr)
{
    displayStateAsBytes(1, "Input of permutation", (const unsigned char *)state);
    for(nr=nrRounds-nr; nr<nrRounds; nr++)
		KeccakF200Round(state, nr);
    displayStateAsBytes(1, "State after permutation", (const unsigned char *)state);
}
