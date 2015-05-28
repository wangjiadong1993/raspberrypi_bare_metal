// #ifndef GPIO_FUNCTION_H
// #define GPIO_FUNCTION_H

/*						ALT0    	ALT1 		ALT2 		ALT3 			ALT4 		ALT5
		GPIO0 	High 	SDA0 		SA5 		<reserved>
		GPIO1 	High 	SCL0 		SA4 		<reserved>
		GPIO2 	High 	SDA1 		SA3 		<reserved>
		GPIO3 	High 	SCL1 		SA2 		<reserved>
		GPIO4 	High 	GPCLK0 		SA1 		<reserved> 								ARM_TDI
		GPIO5 	High 	GPCLK1 		SA0 		<reserved> 								ARM_TDO
		GPIO6 	High 	GPCLK2 		SOE_N/SE 	<reserved> 								ARM_RTCK
		GPIO7 	High 	SPI0_CE1_N 	SWE_N/SRW_N	<reserved>
		GPIO8 	High 	SPI0_CE0_N 	SD0 		<reserved>
		GPIO9 	Low 	SPI0_MISO 	SD1 		<reserved>
		GPIO10 	Low 	SPI0_MOSI 	SD2 		<reserved>
		GPIO11 	Low 	SPI0_SCLK 	SD3 		<reserved>
		GPIO12 	Low 	PWM0 		SD4 		<reserved> 								ARM_TMS
		GPIO13 	Low 	PWM1 		SD5 		<reserved> 								ARM_TCK
		GPIO14 	Low 	TXD0 		SD6 		<reserved> 								TXD1
		GPIO15 	Low 	RXD0 		SD7 		<reserved> 								RXD1
		GPIO16 	Low 	<reserved> 	SD8 		<reserved> 	CTS0 			SPI1_CE2_N 	CTS1
		GPIO17 	Low 	<reserved> 	SD9 		<reserved> 	RTS0 			SPI1_CE1_N 	RTS1
		GPIO18 	Low 	PCM_CLK 	SD10 		<reserved> 	BSCSL SDA/MOSI 	SPI1_CE0_N 	PWM0
		GPIO19 	Low 	PCM_FS 		SD11 		<reserved> 	BSCSL SCL/SCLK 	SPI1_MISO 	PWM1
		GPIO20 	Low 	PCM_DIN 	SD12 		<reserved> 	BSCSL /MISO 	SPI1_MOSI 	GPCLK0
		GPIO21 	Low 	PCM_DOUT 	SD13 		<reserved> 	BSCSL /CE_N 	SPI1_SCLK 	GPCLK1
		GPIO22 	Low 	<reserved> 	SD14 		<reserved> 	SD1_CLK 		ARM_TRST
		GPIO23 	Low 	<reserved> 	SD15 		<reserved> 	SD1_CMD 		ARM_RTCK
		GPIO24 	Low 	<reserved> 	SD16 		<reserved> 	SD1_DAT0 		ARM_TDO
		GPIO25 	Low 	<reserved> 	SD17 		<reserved> 	SD1_DAT1 		ARM_TCK
		GPIO26 	Low 	<reserved> 	<reserved> 	<reserved> 	SD1_DAT2 		ARM_TDI
		GPIO27 	Low 	<reserved> 	<reserved> 	<reserved> 	SD1_DAT3 		ARM_TMS
		GPIO28 	- 		SDA0 		SA5 		PCM_CLK 	<reserved>
		GPIO29 	- 		SCL0 		SA4 		PCM_FS 		<reserved>
		GPIO30 	Low 	<reserved> 	SA3 		PCM_DIN 	CTS0 						CTS1
		GPIO31 	Low 	<reserved> 	SA2 		PCM_DOUT 	RTS0 						RTS1
		GPIO32 	Low 	GPCLK0 		SA1 		<reserved> 	TXD0 						TXD1
		GPIO33 	Low 	<reserved> 	SA0 		<reserved> 	RXD0 						RXD1
		GPIO34 	High 	GPCLK0 		SOE_N/SE 	<reserved> 	<reserved>
		GPIO35 	High 	SPI0_CE1_N 	SWE_N/SRW_N				<reserved>
		GPIO36 	High 	SPI0_CE0_N 	SD0 		TXD0 		<reserved>
		GPIO37 	Low 	SPI0_MISO 	SD1 		RXD0 		<reserved>
		GPIO38 	Low 	SPI0_MOSI 	SD2 		RTS0 		<reserved>
		GPIO39 	Low 	SPI0_SCLK 	SD3 		CTS0 		<reserved>
		GPIO40 	Low 	PWM0 		SD4 					<reserved> 		SPI2_MISO 	TXD1 

		GPIO41 	Low 	PWM1 		SD5 		<reserved> 	<reserved> 		SPI2_MOSI 	RXD1
		GPIO42 	Low 	GPCLK1 		SD6 		<reserved> 	<reserved> 		SPI2_SCLK 	RTS1
		GPIO43 	Low 	GPCLK2 		SD7 		<reserved> 	<reserved> 		SPI2_CE0_N 	CTS1
		GPIO44 	- 		GPCLK1 		SDA0 		SDA1 		<reserved> 		SPI2_CE1_N
		GPIO45 	- 		PWM1 		SCL0 		SCL1 		<reserved> 		SPI2_CE2_N
		GPIO46 	High 	<Internal>
		GPIO47 	High 	<Internal>
		GPIO48 	High 	<Internal>
		GPIO49 	High 	<Internal>
		GPIO50 	High 	<Internal>
		GPIO51 	High 	<Internal>
		GPIO52 	High 	<Internal>
		GPIO53 	High 	<Internal> 
*/


/*
SDA0 		BSC master 0 data line 		BSC
SCL0 		BSC master 0 clock line 	BSC
SDA1 		BSC master 1 data line 		BSC
SCL1 		BSC master 1 clock line 	BSC
GPCLK0 		General purpose Clock 0 	<TBD>
GPCLK1 		General purpose Clock 1 	<TBD>
GPCLK2 		General purpose Clock 2 	<TBD>
SPI0_CE1_N 	SPI0 Chip select 1 			SPI
SPI0_CE0_N 	SPI0 Chip select 0 			SPI
SPI0_MISO 	SPI0 MISO 					SPI
SPI0_MOSI 	SPI0 MOSI 					SPI
SPI0_SCLK 	SPI0 Serial clock 			SPI
PWMx 		Pulse 	Width Modulator 0..1 Pulse Width Modulator
TXD0 		UART 	0 Transmit Data 	UART
RXD0 		UART 	0 Receive Data 		UART
CTS0 		UART 	0 Clear To Send 	UART
RTS0 		UART 0 Request To Send 		UART
PCM_CLK 	PCM clock PCM 				Audio
PCM_FS 		PCM Frame Sync PCM 			Audio
PCM_DIN 	PCM Data in PCM 			Audio
PCM_DOUT 	PCM data out PCM 			Audio
SAx 		Secondary mem Address bus 	Secondary Memory Interface
SOE_N/SE 	Secondary mem. Controls 	Secondary Memory Interface
SWE_N/SRW_N Secondary mem. Controls 	Secondary Memory Interface
SDx 		Secondary mem. data bus 	Secondary Memory Interface
BSCSL SDA/MOSI 		BSC slave Data, SPI salve MOSI 		BSC ISP slave
BSCSL SCL / SCLK 	BSC slave Clock, SPI slave clock 	BSC ISP slave
BSCSL - / MISO 		BSC <not used>,SPI MISO 			BSC ISP slave
BSCSL - / CE_N 		BSC <not used>, SPI CSn 			BSC ISP slave 

SPI1_CEx_N 			SPI1 Chip select 0-2 				Auxiliary I/O
SPI1_MISO 			SPI1 MISO 							Auxiliary I/O
SPI1_MOSI 			SPI1 MOSI 							Auxiliary I/O
SPI1_SCLK 			SPI1 Serial clock 					Auxiliary I/O
TXD0 				UART 1 Transmit Data 				Auxiliary I/O
RXD0 				UART 1 Receive Data 				Auxiliary I/O
CTS0 				UART 1 Clear To Send 				Auxiliary I/O
RTS0 				UART 1 Request To Send 				Auxiliary I/O
SPI2_CEx_N 			SPI2 Chip select 0-2 				Auxiliary I/O
SPI2_MISO 			SPI2 MISO 							Auxiliary I/O
SPI2_MOSI 			SPI2 MOSI 							Auxiliary I/O
SPI2_SCLK 			SPI2 Serial clock 					Auxiliary I/O
ARM_TRST 			ARM JTAG reset 						<TBD>
ARM_RTCK 			ARM JTAG return clock 				<TBD>
ARM_TDO 			ARM JTAG Data out 					<TBD>
ARM_TCK 			ARM JTAG Clock 						<TBD>
ARM_TDI 			ARM JTAG Data in 					<TBD>
ARM_TMS 			ARM JTAG Mode select 				<TBD> 
*/

#define GPIO_ALT0 	100	
#define GPIO_ALT1 	101
#define GPIO_ALT2 	110
#define GPIO_ALT3 	111
#define GPIO_ALT4 	011
#define GPIO_ALT5 	010

#define GPIO_PULL_UP 	1
#define GPIO_PULL_DOWN 	0



