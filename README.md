<br>

본 프로젝트에서는 STM32의 내장되어있는 **bxCAN**을 사용하여 두 개의 MCU 간 CAN 통신을 주고 받는 **송수신 테스트**를 진행하였으며 이를 PC 터미널 창에 띄어서 확인해보는 과정을 나타냅니다. <br>

STM32 Connectivity Line을 제외한 F1 시리즈 STM32들은 데이터 송수신에 사용되는 512Byte RAM을 USB와 CAN이 공유하기 때문에 **USB와 CAN을 동시에 사용하지 못합니다.**
CAN과 USB를 동시에 사용해야 한다면 STM32F105/7이나 F2 시리즈 등 다른 시리즈의 STM32를 사용하시길 바랍니다. <br>

**CAN 통신에 대하여 이해가 부족하신 분이라면 아래의 사이트를 참고하세요.** <br>

* 맨위의 동영상은 **8bit AVR MCU** 기준의 CAN 통신을 위한 레지스터 설정법을 설명해 준다면, **32bit STM32 MCU**를 사용한 CAN 설정법의 경우에는 아래 두 사이트 및 영상을 참고하세요.. 

* **Microchip Technology - Korean** YouTube 
  + [CAN/CAN-FD Basic Part 1: CAN 개요 및 프로토콜 1](https://www.youtube.com/watch?v=9A3YRYla4WI) 
  + [CAN/CAN-FD Basic Part 2: CAN 프로토콜 2](https://www.youtube.com/watch?v=dqacvllM-UA) 
  + [CAN/CAN-FD Basic Part 3: CAN 에러 핸들링과 비트 타이밍 설정](https://www.youtube.com/watch?v=zyzz_3KW9GY) 
  + [CAN/CAN-FD Basic Part 4: CAN과 CAN FD](https://www.youtube.com/watch?v=IeK2TSGX5ms) 
  + [CAN/CAN-FD Basic Part 5: 실습 설명](https://www.youtube.com/watch?v=rg2LA0o98dM) 

* **Wonyeob Chris Park** YouTube   
  + [[HAL, CubeMX, TrueSTUDIO를 이용한 STM32F4 속성 강의 강좌] 13-1강. CAN 통신 개념](https://www.youtube.com/watch?v=84IAJDuJdxc&list=PLUaCOzp6U-RqMo-QEJQOkVOl1Us8BNgXk&index=21)
  + [[HAL, CubeMX, TrueSTUDIO를 이용한 STM32F4 속성 강의 강좌] 13-2강. CAN 설정 및 송신코드 작성](https://www.youtube.com/watch?v=6vR3lX8ojDA&list=PLUaCOzp6U-RqMo-QEJQOkVOl1Us8BNgXk&index=22)
  + [[HAL, CubeMX, TrueSTUDIO를 이용한 STM32F4 속성 강의 강좌] 13-3강. CAN 필터 MASK ID 설정 및 수신코드 작성 (완)](https://www.youtube.com/watch?v=T65WpTyv8Po&list=PLUaCOzp6U-RqMo-QEJQOkVOl1Us8BNgXk&index=23)
 
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
### 구성도

<br>

<p align="center">
   <img src="https://user-images.githubusercontent.com/70312248/166689921-8942e3f5-cbc7-4579-b37d-1329d7883a4e.png" width="1300" height="500"/>  
</p>  
