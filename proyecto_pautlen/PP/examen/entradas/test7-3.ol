main
{

    int v1, v2, v3;
    boolean v4;

    function int f1 (boolean pf1; boolean pf2){
      int vl1;
      boolean vl2;

      vl1 = 1;
      v1 = 40;
      vl2 = false;

      if (pf1){
          vl1=v1+2;
          vl2 = true;
          printf 2;

      }
      printf vl2;

	    return vl1;
    }

    function int f2 (boolean pf1){
      int vl3;
      boolean vl4;

      vl1 = 1; // ERROR

      v1 = 40;
      vl2 = false;

      if (pf1){
          vl1=v1+2;
          vl2 = true;
          printf 2;
      }
      printf vl2;

      return vl1;
    }

    v1 = 1;
    v4 = true;
    v2 = f1 (v4, true);

    v3 = f2 (false);


    printf v2;
    printf v3;
    printf v4;
}
