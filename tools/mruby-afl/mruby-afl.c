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
  
  /* open mruby interpreter instance */
  mrb = mrb_open();

  while (__AFL_LOOP(1000)) {
    /* load new source */
    in = fopen(argv[1], "r");

    /* execute ruby code */
    mrb_load_file(mrb, in);

    /* load new source */
    fclose(in);
  }
  
  /* cleanup mruby */
  mrb_close(mrb);

  return 0;
}

