#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* This utility mimics "hexdump -C" on e.g. MacOS:
00000000  cf fa ed fe 07 00 00 01  03 00 00 80 02 00 00 00  |................|
00000010  10 00 00 00 60 05 00 00  85 00 20 00 00 00 00 00  |....`..... .....|
00000020  19 00 00 00 48 00 00 00  5f 5f 50 41 47 45 5a 45  |....H...__PAGEZE|
00000030  52 4f 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |RO..............|
*/

#define SEGMENTS_PER_LINE (2)
#define BYTES_PER_SEGMENT (8)

#define BYTES_PER_LINE    (SEGMENTS_PER_LINE * BYTES_PER_SEGMENT)

int main() {
  int pos, c, cur_byte = 0;
  char tmpbuf[9], outbuf[10 + BYTES_PER_LINE * 3 + SEGMENTS_PER_LINE + BYTES_PER_LINE + 4];
  while (!feof(stdin)) {
    pos = cur_byte % BYTES_PER_LINE;
    if (pos == 0) {
      if (cur_byte > 0)
        printf("%s\n", outbuf);
      memset(outbuf, ' ', sizeof(outbuf));
      outbuf[sizeof(outbuf)-1] = '\0';
      sprintf(tmpbuf, "%08x", cur_byte);
      memcpy(outbuf, tmpbuf, 8);
      outbuf[BYTES_PER_LINE * 3 + 12] = outbuf[BYTES_PER_LINE * 4 + 14] = '|';
    }
    if ((c = getc(stdin)) == -1)
      break;
    sprintf(tmpbuf, "%02x", c);
    memcpy(outbuf + 10 + (pos * 3) + ((int)(pos/BYTES_PER_SEGMENT)), tmpbuf, 2);
    outbuf[13 + BYTES_PER_LINE * 3 + ((int)(pos / BYTES_PER_SEGMENT)) + pos] = isprint(c) ? c : '.';
    cur_byte += 1;
  }
  printf("%s\n", outbuf);
  return 0;
}


