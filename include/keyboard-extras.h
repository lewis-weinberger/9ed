#ifndef _KEYBOARD_EXTRAS_H_
#define _KEYBOARD_EXTRAS_H_ 1

#if defined(__cplusplus)
extern "C" {
#endif

enum {
	Ketx = 0x03,	/* ^C, end of text */
	Kdc3 = 0x13,	/* ^S, device control 3 */
	Ksyn = 0x16,	/* ^V, synchronous idle */
	Kcan = 0x18,	/* ^X, cancel */
	Keom = 0x19,	/* ^Y, end of medium */
	Ksub = 0x1A,	/* ^Z, substitute */

	Kmod4 = 0xF200,	/* Mod4 bindings */
	Ksh = 0xF300,	/* Shift modified bindings */
	Kcret = 0xF400,	/* Control + Return */
};

#if defined(__cplusplus)
}
#endif

#endif /* _KEYBOARD_EXTRAS_H_ */