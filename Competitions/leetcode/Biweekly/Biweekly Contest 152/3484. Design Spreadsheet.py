class Spreadsheet:

    def __init__(self, rows: int):
        self.mat = [[0] * 26 for _ in range(rows)]

    def setCell(self, cell: str, value: int) -> None:
        col = ord(cell[0])-ord('A')
        row = int(cell[1:])-1
        
        self.mat[row][col] = value
        
    def resetCell(self, cell: str) -> None:
        self.setCell(cell, 0)
        
    def getValue(self, formula: str) -> int:
        attrs = formula[1:].split('+')
        x = attrs[0]
        b = attrs[1]
        
        res = 0
        for a in [x, b]:
            try:
                res += int(a)
            except:
                col = ord(a[0])-ord('A')
                row = int(a[1:])-1
                res += self.mat[row][col]
                
        return res
        
        
        


# Your Spreadsheet object will be instantiated and called as such:
# obj = Spreadsheet(rows)
# obj.setCell(cell,value)
# obj.resetCell(cell)
# param_3 = obj.getValue(formula)