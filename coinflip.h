#ifndef COINFLIP_H
#define COINFLIP_H

/** Flips a coin when the user hits enter.
 * 	Records flip statistics, and outputs them
 * 	at user request or when user quits.
 */
void coinflipper();

/** Flip calculation */
static char flip();

/* 		Quick Percentage calculation for prints		*/
static float percentage(int total, int part);


#endif