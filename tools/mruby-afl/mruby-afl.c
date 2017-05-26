#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mruby.h>
#include <mruby/compile.h>

int
main(int argc, char **argv)
{
  mrb_state *mrb;
  FILE *in;

  while (__AFL_LOOP(1000)) {
    // init || re-int code and load new source
    mrb = mrb_open();
    in = fopen(argv[1], "r");

    // execute
    mrb_load_file(mrb, in);

    // clean up
    fclose(in);
    mrb_close(mrb);
  }

  return 0;
}
