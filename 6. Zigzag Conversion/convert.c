/* At first, I don't really understand what is zigzag. In fact, it' like:

0       6        12
1    5  7     11
2  4    8  10
3       9

then it's much simpler! */

char* convert(char* s, int numRows) {
    int len = strlen(s);
    if(len <= numRows || numRows == 1)
        return s;
    
    // Go down and up makes a unit.
    int unit_step = 2 * numRows - 2;
    
    int pos = 0;
    char *new_s = (char*)calloc((len + 1), sizeof(char));
    for(int i = 0; i < numRows; ++i){
        int j = i;
        int curr_step = unit_step - 2 * i;  // Must be re-calculated each row.
        while(j < len){
            new_s[pos++] = s[j];
            if(!(i == 0 || i == numRows-1))
                if(j + curr_step < len)
                    new_s[pos++] = s[j + curr_step];
            j += unit_step;
        }
    }
    return new_s;
}