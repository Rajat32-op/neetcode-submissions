class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        for(int i=0;i<16;i++){
            int x=(n>>i)&1;
            int y=(n>>(31-i))&1;
            if(x==y)continue;
            n^=(1<<i);
            n^=(1<<(31-i));
        }
        return n;
    }
};
