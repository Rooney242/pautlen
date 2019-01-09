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
      else{
        if (pf2){
          printf 10;
        }
      }
      printf vl2;

	    // ERROR return vl1;
    }

    v1 = 1;
    v4 = true;
    v2 = f1 (v4, true);

    v3 = f1 (false, true);


    printf v2;
    printf v3;
    printf v4;
}
