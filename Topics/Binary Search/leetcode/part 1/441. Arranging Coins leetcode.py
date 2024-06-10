class Solution(object):
    def arrangeCoins(self, n):
        # formula: max_row_number = (sqrt(1+8*n)-1)/2;
        i = 1
        j = 65536
        
        while i<j:
            mid = (i+j+1)/2 # 3dad tab9at eli najem na3mlhom
            coins = mid * (mid+1) / 2 # 3dad coins eli ykhaliwni naamel mid tab9at
            if coins == n:
                return mid
            elif coins > n:
                j = mid - 1
            else:
                i = mid
            
        return i