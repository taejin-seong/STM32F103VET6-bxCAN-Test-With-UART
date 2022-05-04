## 개발 환경<br>
### IDE
* STM32CubeIDE 1.6.0 <br>
* STM32CubeMX <br>

### 개발 보드
* **STM32F103VET6 Custom Development Board** <br>
  + :pushpin: [이미지 링크 및 구매처](https://ko.aliexpress.com/item/32693544239.html?gatewayAdapt=glo2kor&srcSns=sns_KakaoTalk&spreadType=socialShare&bizType=ProductDetail&social_params=20527276655&aff_fcid=6a92134b6f66447fb4e5392261410de1-1649825428883-09137-_mMqvBK2&tt=MG&aff_fsk=_mMqvBK2&aff_platform=default&sk=_mMqvBK2&aff_trace_key=6a92134b6f66447fb4e5392261410de1-1649825428883-09137-_mMqvBK2&shareId=20527276655&businessType=ProductDetail&platform=AE&terminal_id=62559df8374f42348f14bc09e497c7f3&afSmartRedirect=y)<br>
  
  + :pushpin: [개발보드 회로도](https://github.com/taejin-seong/STM32F103VET6-TFT-LCD-with-Resistive-Touch-Screen/blob/master/STM32F103VET6%20Dev%20Board%20Schematic/0001.jpg)<br>
    - 제공되는 개발보드 회로도를 확인해 본 결과, 회로도에 표기되어있는 커넥터 및 핀 헤더명이 실제 보드의 커넥터 및 핀 헤더명과 서로 다른 것을 확인하였습니다. **이를 주의하시고** 회로도를  보시길 바랍니다. <br><br>
    <p align="center">
     <img src="https://user-images.githubusercontent.com/70312248/163129584-df167919-aa90-44d1-8b6c-c36210542ddc.png" width="450" height="330"/>     
     <img src="https://user-images.githubusercontent.com/70312248/163130781-470699c0-dcd2-41bd-8334-20412fc8dda7.png" width="400" height="300"/> </p><br>
 
### CAN 트랜시버 모듈
* **SN65HVD230 CAN Board** <br>
  + :pushpin: [이미지 링크 및 구매처](https://www.waveshare.com/sn65hvd230-can-board.htm) <br>
  
  + :pushpin: [해당 트랜시버 모듈 데이터시트 및 회로도](http://www.lcdwiki.com/3.2inch_16BIT_Module_ILI9341_SKU:MRB3205)<br>
    - 사용한 CAN 트랜시버 모듈에는 **종단저항 120Ω**이 실장되어 있으므로 따로 종단저항을 구성하여 회로를 설계하지 않아도 됩니다.
    <p align="left">
      <img src="https://user-images.githubusercontent.com/70312248/166659781-9d3564de-2242-437e-a356-74de3ff1e046.jpg" width="380" height="380"/> 
      <img src="https://user-images.githubusercontent.com/70312248/166659288-7debcb52-83cb-4e70-aa4e-5cef46597f41.png" width="550" height="300"/>  
    </p>  
    
 
