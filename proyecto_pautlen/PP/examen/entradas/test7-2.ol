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
      printf 80;
      printf vl2;
      printf 500;

      if (pf1){
          vl1=v1+2;
          vl2 = true;
          printf 2;

      }
      printf vl2;
      vl2 = false;
      printf 70;
      printf vl2;
      printf 90;

	    return vl1;
    }

    function int f2 (boolean pf1){
      int vl1;
      boolean vl2;

      vl1 = 90;
      v1 = 40;
      printf 800;
      vl2 = false;
      printf vl2;
      vl1 = 0;
      printf vl1;
      printf 1000;
      printf vl2;
      printf 2000;

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

    printf f1 (v4, true);
    printf f2 (false);
    printf v1;
    printf v4;
}
