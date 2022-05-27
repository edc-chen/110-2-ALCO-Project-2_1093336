# Project-2 **3-bit History Predictor**

## 詳細程式碼說明連結
(https://youtu.be/WiS_WKwDBwk)
## 資料說明
* **./Pro/project2_proOutput.txt** 對應為 **./testData/test.txt** 的輸出 
  - 此筆測試資料為 **HackMD** 上面的範例Code但是因為沒有製作 **li** 所以用 **addi** 替換
  - 使用的 **instruction** 有 **add** , **addi** , **andi** , **beq** , **bne**
* **./Pro/project2_proOutput2.txt** 對應為 **./testData/test2.txt** 的輸出
  - 此筆測資為底下的範例
  - 使用的 **instruction** 有 **addi** , **beq**

## 支援的instruction
add, addi, and, beq, bne

## 輸入範例

```
0x110           addi R1,R0,16;  //R1=16
0x114           addi  R2,R0,0; //R2=0
        LoopI:
0x118           beq R1,R2,EndLoopI; //R1==R2 EndLoopI
0x11C           addi R2,R2,1; //R2+=1
0x120   beq R0,R0,LoopI; //Go back to LoopI
        EndLoopI:
```

## 範例執行結果
```
Enter entry number: 2
Input File: 
============================================
0x110           addi R1,R0,16;  //R1=16
0x114           addi  R2,R0,0; //R2=0
        LoopI:
0x118           beq R1,R2,EndLoopI; //R1==R2 EndLoopI
0x11C           addi R2,R2,1; //R2+=1
0x120   beq R0,R0,LoopI; //Go back to LoopI
        EndLoopI:
============================================

============================================
Inst. : addi R1,R0,16 
Use Entry: 0
Entry 0 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 0
============================================
Inst. : addi R2,R0,0 
Use Entry: 1
Entry 0 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 0
============================================
Inst. : beq R1,R2,EndLoopI 
Use Entry: 0
Entry 0 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 0
============================================
Inst. : addi R2,R2,1 
Use Entry: 1
Entry 0 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 0
============================================
Inst. : beq R0,R0,LoopI 
Use Entry: 0
Entry 0 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N T Predict Fail
Misprediction: 1
============================================
Inst. : beq R1,R2,EndLoopI 
Use Entry: 0
Entry 0 : (001, WN, SN, SN, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 1
============================================
Inst. : addi R2,R2,1 
Use Entry: 1
Entry 0 : (010, WN, SN, SN, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 0
============================================
Inst. : beq R0,R0,LoopI 
Use Entry: 0
Entry 0 : (010, WN, SN, SN, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N T Predict Fail
Misprediction: 2
============================================
Inst. : beq R1,R2,EndLoopI 
Use Entry: 0
Entry 0 : (101, WN, SN, WN, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 2
============================================
Inst. : addi R2,R2,1 
Use Entry: 1
Entry 0 : (010, WN, SN, WN, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 0
============================================
Inst. : beq R0,R0,LoopI 
Use Entry: 0
Entry 0 : (010, WN, SN, WN, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N T Predict Fail
Misprediction: 3
============================================
Inst. : beq R1,R2,EndLoopI 
Use Entry: 0
Entry 0 : (101, WN, SN, WT, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 3
============================================
Inst. : addi R2,R2,1 
Use Entry: 1
Entry 0 : (010, WN, SN, WT, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 0
============================================
Inst. : beq R0,R0,LoopI 
Use Entry: 0
Entry 0 : (010, WN, SN, WT, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
T T Predict Success
Misprediction: 3
============================================
Inst. : beq R1,R2,EndLoopI 
Use Entry: 0
Entry 0 : (101, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 3
============================================
Inst. : addi R2,R2,1 
Use Entry: 1
Entry 0 : (010, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 0
============================================
Inst. : beq R0,R0,LoopI 
Use Entry: 0
Entry 0 : (010, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
T T Predict Success
Misprediction: 3
============================================
Inst. : beq R1,R2,EndLoopI 
Use Entry: 0
Entry 0 : (101, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 3
============================================
Inst. : addi R2,R2,1 
Use Entry: 1
Entry 0 : (010, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 0
============================================
Inst. : beq R0,R0,LoopI 
Use Entry: 0
Entry 0 : (010, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
T T Predict Success
Misprediction: 3
============================================
Inst. : beq R1,R2,EndLoopI 
Use Entry: 0
Entry 0 : (101, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 3
============================================
Inst. : addi R2,R2,1 
Use Entry: 1
Entry 0 : (010, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 0
============================================
Inst. : beq R0,R0,LoopI 
Use Entry: 0
Entry 0 : (010, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
T T Predict Success
Misprediction: 3
============================================
Inst. : beq R1,R2,EndLoopI 
Use Entry: 0
Entry 0 : (101, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 3
============================================
Inst. : addi R2,R2,1 
Use Entry: 1
Entry 0 : (010, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 0
============================================
Inst. : beq R0,R0,LoopI 
Use Entry: 0
Entry 0 : (010, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
T T Predict Success
Misprediction: 3
============================================
Inst. : beq R1,R2,EndLoopI 
Use Entry: 0
Entry 0 : (101, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 3
============================================
Inst. : addi R2,R2,1 
Use Entry: 1
Entry 0 : (010, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 0
============================================
Inst. : beq R0,R0,LoopI 
Use Entry: 0
Entry 0 : (010, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
T T Predict Success
Misprediction: 3
============================================
Inst. : beq R1,R2,EndLoopI 
Use Entry: 0
Entry 0 : (101, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 3
============================================
Inst. : addi R2,R2,1 
Use Entry: 1
Entry 0 : (010, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 0
============================================
Inst. : beq R0,R0,LoopI 
Use Entry: 0
Entry 0 : (010, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
T T Predict Success
Misprediction: 3
============================================
Inst. : beq R1,R2,EndLoopI 
Use Entry: 0
Entry 0 : (101, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 3
============================================
Inst. : addi R2,R2,1 
Use Entry: 1
Entry 0 : (010, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 0
============================================
Inst. : beq R0,R0,LoopI 
Use Entry: 0
Entry 0 : (010, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
T T Predict Success
Misprediction: 3
============================================
Inst. : beq R1,R2,EndLoopI 
Use Entry: 0
Entry 0 : (101, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 3
============================================
Inst. : addi R2,R2,1 
Use Entry: 1
Entry 0 : (010, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 0
============================================
Inst. : beq R0,R0,LoopI 
Use Entry: 0
Entry 0 : (010, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
T T Predict Success
Misprediction: 3
============================================
Inst. : beq R1,R2,EndLoopI 
Use Entry: 0
Entry 0 : (101, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 3
============================================
Inst. : addi R2,R2,1 
Use Entry: 1
Entry 0 : (010, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 0
============================================
Inst. : beq R0,R0,LoopI 
Use Entry: 0
Entry 0 : (010, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
T T Predict Success
Misprediction: 3
============================================
Inst. : beq R1,R2,EndLoopI 
Use Entry: 0
Entry 0 : (101, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 3
============================================
Inst. : addi R2,R2,1 
Use Entry: 1
Entry 0 : (010, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 0
============================================
Inst. : beq R0,R0,LoopI 
Use Entry: 0
Entry 0 : (010, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
T T Predict Success
Misprediction: 3
============================================
Inst. : beq R1,R2,EndLoopI 
Use Entry: 0
Entry 0 : (101, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 3
============================================
Inst. : addi R2,R2,1 
Use Entry: 1
Entry 0 : (010, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 0
============================================
Inst. : beq R0,R0,LoopI 
Use Entry: 0
Entry 0 : (010, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
T T Predict Success
Misprediction: 3
============================================
Inst. : beq R1,R2,EndLoopI 
Use Entry: 0
Entry 0 : (101, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 3
============================================
Inst. : addi R2,R2,1 
Use Entry: 1
Entry 0 : (010, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N N Predict Success
Misprediction: 0
============================================
Inst. : beq R0,R0,LoopI 
Use Entry: 0
Entry 0 : (010, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
T T Predict Success
Misprediction: 3
============================================
Inst. : beq R1,R2,EndLoopI 
Use Entry: 0
Entry 0 : (101, WN, SN, ST, SN, SN, SN, SN, SN)
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)
N T Predict Fail
Misprediction: 4
====================Done====================
Predictors:
Entry 0 : (011, WN, SN, ST, SN, SN, WN, SN, SN)Misprediction: 4
Entry 1 : (000, SN, SN, SN, SN, SN, SN, SN, SN)Misprediction: 0

```
