//
// Created by Theo on 2017/7/5.
//

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int row = abs(C-A);
        int col = abs(D-B);

        int area = row*col;
        row = abs(G-E);
        col = abs(H-F);
        area+=row*col;

        //int middle area
        int left = E>A?E:A;
        int right = C<G?C:G;
        if(right<left)
            return area;

        row = right-left;
        left = B>F?B:F;
        right = H<D?H:D;
        if(right<left)
            return area;

        col = right-left;
        if(row<0||col<0)
            return area;
        return area-row*col;
    }
};