;基本模型机程序

#LOAD "shiyan.IS"         ;预调入指令系统/微程序
#SET RAM 0260h = 5500h  ;数据区0260H单元预置数据5500h
#SET RAM 0280h = 0100h  ;
#SET RAM 0290h = 1111h  ;
#SET RAM 0123h = 5555h  ;

data    segment         ;将程序装载到数据存储器
        assume ds:data

        org   0
start:  in    r0, iol   ;IO->r0

        sub   r0 ,0280h    ;  a - b
        add   r0, 0260h    ;
        
        sta   0261h, r0   ;  0261h - > 8080
        
        out   ioh, 0261h
        shl   R0,1

        and   r0,0123h  ; 80 and 0
        mov   ax,r0
        
        rrc   r0
        
        jmp   start
        
data    ends
        end   start
