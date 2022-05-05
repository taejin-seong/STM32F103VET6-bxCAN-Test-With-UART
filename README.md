
본 프로젝트에서는 STM32의 내장되어있는 **bxCAN**을 사용하여 두 개의 STM32F103VET6 MCU 간 CAN 통신을 주고 받는 **송수신 테스트**를 진행하였으며 이를 PC 터미널 창에 띄어서 확인해보는 과정을 나타냅니다. 

<br>

<p align="center">
   <img src="https://user-images.githubusercontent.com/70312248/166745024-3e3cb3fd-df1a-4096-ae10-b89c11763607.png" width="435" height="400"/>  
</p>  

<br>

참고로 STM32 Connectivity Line을 제외한 F1 시리즈 STM32들은 데이터 송수신에 사용되는 512byte RAM을 USB와 CAN이 공유하기 때문에 **USB와 CAN을 동시에 사용하지 못합니다.**
따라서 CAN과 USB를 동시에 사용해야 한다면 STM32F105/7이나 F2 시리즈 등 다른 시리즈의 STM32를 사용하시길 바랍니다. <br>

해당 프로젝트는 CAN 통신에 대한 **기본적인 이해**와 CAN 통신을 위한 **기본적인 설정법**에 대한 학습이 필요합니다. <br>
아래 사이트를 참고하여 학습하는 것을 추천합니다.

<br>

CAN/CAN-FD 통신의 이론적 소개와 8bit AVR MCU에서의 CAN 통신을 위한 레지스터 설정법을 다뤄줍니다.
* **Microchip Technology - Korean** YouTube 
  + [CAN/CAN-FD Basic Part 1: CAN 개요 및 프로토콜 1](https://www.youtube.com/watch?v=9A3YRYla4WI) 
  + [CAN/CAN-FD Basic Part 2: CAN 프로토콜 2](https://www.youtube.com/watch?v=dqacvllM-UA) 
  + [CAN/CAN-FD Basic Part 3: CAN 에러 핸들링과 비트 타이밍 설정](https://www.youtube.com/watch?v=zyzz_3KW9GY) 
  + [CAN/CAN-FD Basic Part 4: CAN과 CAN FD](https://www.youtube.com/watch?v=IeK2TSGX5ms) 
  + [CAN/CAN-FD Basic Part 5: 실습 설명](https://www.youtube.com/watch?v=rg2LA0o98dM) 

<br>

CAN 통신의 이론적 소개와 32bit STM32F4 MCU에서의 CAN 통신을 위한 설정법을 다뤄줍니다.
* **Wonyeob Chris Park** YouTube
  + [[HAL, CubeMX, TrueSTUDIO를 이용한 STM32F4 속성 강의 강좌] 13-1강. CAN 통신 개념](https://www.youtube.com/watch?v=84IAJDuJdxc&list=PLUaCOzp6U-RqMo-QEJQOkVOl1Us8BNgXk&index=21)
  + [[HAL, CubeMX, TrueSTUDIO를 이용한 STM32F4 속성 강의 강좌] 13-2강. CAN 설정 및 송신코드 작성](https://www.youtube.com/watch?v=6vR3lX8ojDA&list=PLUaCOzp6U-RqMo-QEJQOkVOl1Us8BNgXk&index=22)
  + [[HAL, CubeMX, TrueSTUDIO를 이용한 STM32F4 속성 강의 강좌] 13-3강. CAN 필터 MASK ID 설정 및 수신코드 작성 (완)](https://www.youtube.com/watch?v=T65WpTyv8Po&list=PLUaCOzp6U-RqMo-QEJQOkVOl1Us8BNgXk&index=23)

<br>

CAN 통신의 이론적 소개와 2bit STM32F0 MCU에서의 CAN 통신을 위한 레지스터 설정법을 다뤄줍니다.
* **Joon-Lab 기술블로그**
  + [STM32를 이용해 Control Area Network (CAN) 통신 이해 - 목차](https://blog.joon-lab.com/23)

<br>

## 개발 환경<br>
### IDE
* STM32CubeIDE 1.6.0 <br>
* STM32CubeMX <br>

### 개발 보드
* **STM32F103VET6 Custom Development Board** <br>
  + :pushpin: [이미지 링크 및 구매처](https://ko.aliexpress.com/item/32693544239.html?gatewayAdapt=glo2kor&srcSns=sns_KakaoTalk&spreadType=socialShare&bizType=ProductDetail&social_params=20527276655&aff_fcid=6a92134b6f66447fb4e5392261410de1-1649825428883-09137-_mMqvBK2&tt=MG&aff_fsk=_mMqvBK2&aff_platform=default&sk=_mMqvBK2&aff_trace_key=6a92134b6f66447fb4e5392261410de1-1649825428883-09137-_mMqvBK2&shareId=20527276655&businessType=ProductDetail&platform=AE&terminal_id=62559df8374f42348f14bc09e497c7f3&afSmartRedirect=y)<br>
  
  + :pushpin: [개발보드 회로도](https://github.com/taejin-seong/STM32F103VET6-bxCAN-Test-With-UART/tree/master/STM32F103VET6%20Dev%20Board%20Schematic)<br>
    - 제공되는 개발보드 회로도를 확인해 본 결과, 회로도에 표기되어있는 커넥터 및 핀 헤더명이 실제 보드의 커넥터 및 핀 헤더명과 서로 다른 것을 확인하였습니다. **이를 주의하시고** 회로도를  보시길 바랍니다. <br><br>
 
### CAN 트랜시버 모듈
* **SN65HVD230 CAN Board** <br>
  + :pushpin: [이미지 링크 및 구매처](https://www.waveshare.com/sn65hvd230-can-board.htm) <br>
  
  + :pushpin: [해당 트랜시버 모듈 데이터시트 및 회로도](https://github.com/taejin-seong/STM32F103VET6-bxCAN-Test-With-UART/tree/master/SN65HVD230%20CAN%20Board%20Datasheets%20%26%20Schematic)<br>
    - 사용한 CAN 트랜시버 모듈에는 **종단저항 120Ω**이 실장되어 있으므로 따로 종단저항을 구성하여 회로를 설계하지 않아도 됩니다.
<p align="center">
   <img src="https://user-images.githubusercontent.com/70312248/166659288-7debcb52-83cb-4e70-aa4e-5cef46597f41.png" width="630" height="230"/>  
</p>  
    
 <br>

## 하드웨어 구성<br>
<br>

<p align="center">
   <img src="https://user-images.githubusercontent.com/70312248/166743059-04822ac5-791a-4a33-974b-0aa26f9950d1.png" width="850" height="445"/>  
</p> 

<br><br>

<p align="center">
   <img src="https://user-images.githubusercontent.com/70312248/166893002-3b6dc7fd-1c3b-4f1f-85a4-6257ed2a22a8.png" width="740" height="280"/>  
</p> 


<br>
<br>



## bxCAN 설정<br>

### Baud Rate 설정
* CAN 통신의 Baud Rate를 설정할 때는 **1 bit를 전송하는데 걸리는 시간**을 설정해야함.
* **Baud Rate = 500kbps** 으로 설정하기 위한 과정 

### (1). Prescaler 설정
* Baud Rate는 초당 500k bit이므로 1bit 당 2us가 소요.
* STM32F103VET6의 CAN은 **APB1** 페리페럴 클럭 버스에 달려있음. 
* **APB1**이 **36MHz** 일 때, 이에 따라 **Prescaler를 9** 로 설정함. 즉, 9/36MHz = **0.25us**.
* **0.25us** 단위가 **1개의 타임퀀텀(TQ : Time Quantum (plural: quanta)) 시간 단위**가 됨.


### (2). 1 Bit Time에 TQ를 몇 개 배치할 것인가?
* 1 Bit Time에 **8개**의 TQ를 배치하면 0.25us x 8 = **2us**가 됨.
* 즉, 1 Bit Time에 8개의 TQ를 배치하도록 설정함.
* 여기까지 통신속도 500kbps가 결정됨.


### (3). 1 Bit Time에 TQ를 어떻게 배치할 것인가?
* 8개의 TQ를 **SYNC_SEG**, **BIT SEGMENT 1 (BS1)**, **BIT SEGMENT 2 (BS2)** 에 각각 나눠서 배정.
* **SYNC_SEG**는 **1TQ**로 고정.
* 나머지 **7개의 TQ**를 **BS1**과 **BS2**에 각각 배정해야함. 
* 먼저 **SAMPLE POINT**를 **75%로** 만들기로 결정하고, **SAMPLE POINT**는 다음과 같은 공식으로 정해짐.
   + *Sample Point = (SYNC_SEG + BS1) / Total TQ*  
* 따라서 위의 공식을 이용하면 **75/100 = (1 + BS1) / 8** 이므로 이를 **BS1**에 대하여 풀면 **BS1=5**, 저절로 **BS2=2**
* 그러므로 **SYNC_SEG = 1**, **BS1 = 5**, **BS = 2**의 TQ를 배정받게 됨.
* 여기까지 TQ 배치에 따른 Sample Point가 결정되고, 1 Bit Time이 완성됨.

<br>
<br>

<p align="center">
   <img src="https://user-images.githubusercontent.com/70312248/166937586-d398acdc-11ee-4f66-9799-63b83e7478b0.png" width="550" height="360"/>  
</p> 

<br>

### Filter Mask ID와 Filter ID 설정

<br>
