class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {

        long int areaf = (C - A) * (D - B);
        long int areas = (G - E) * (H - F);
        
        int lx = (A > E) ? A : E;
        int hx = (C < G) ? C : G;
        int ly = (B > F) ? B : F;
        int hy = (D < H) ? D : H;
        
        long long int overlap = 0;
        if((hx > lx) && (hy > ly)){overlap = (hx - lx) * (hy - ly);}
        
        return (areaf + areas - overlap);
    }
};