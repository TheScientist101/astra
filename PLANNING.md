# Planning

This is a mirror of our Slack canvas.

## Features

* Parachute
* Solar Panel
    * https://www.aliexpress.us/item/3256808773901038.html
* Toy Ammunition
* Alternate Terrains
* Perching Mechanism
* Autonomous Navigation
    * Auto-Following
        * Using radio signal or camera
        * One follows another
* Mapping using LiDAR or Camera
    * Fastest path
* Radio Integration
* Aerial Laser Tag
* 6“ x 6”

## Budget

Remember to 2x everything at the end

* ESP32-S2 (ESP32-S2-MINI-1U-N4) -  $3.62
    * https://www.digikey.com/en/products/detail/espressif-systems/ESP32-S2-MINI-1U-N4/13180197
* SPI NOR Flash - $0.56
    * BY25Q64ESTIG
* OV3660 or OV2460 - ~$4 - ~10 grams
* Camera Connector - DF40C-30DP-0.4V - $0.81
    * https://www.digikey.com/en/products/detail/hirose-electric-co-ltd/DF40C-30DP-0-4V-51/1969483
* Solder Paste
    * Digikey NC191LT10
    * Aliexpress https://www.aliexpress.us/item/3256806096656294.html $2.98
* PCB - $20-ish - ~10 grams with components except for camera
* Battery - https://www.getfpv.com/sub250-300mah-1s-75c-lipo-battery-5-pcs-a30.html
* IMU - 
* Set of SMD Capacitors/resistors
    * https://www.aliexpress.us/item/3256805970706203.html - 0805 $4.26 for 320pcs
    * https://www.aliexpress.us/item/3256807716137879.html - 0805 $4.17 for 1000pcs (optional)
* AMS1117 3.3
    * Already have
* Propeller
    * https://hackermotors.us/product/gws-prop-3-x-3-hd-set-with-2-pcs/
* Motor ~ 20 grams for all four
    * https://www.aliexpress.us/item/3256802734081484.html?spm=a2g0o.productlist.main.1.4abd7GOB7GOBIW&algo_pvid=f8b5c9f6-35c2-402f-85a3-de4a12039a17&algo_exp_id=f8b5c9f6-35c2-402f-85a3-de4a12039a17-0&pdp_ext_f=%7B%22order%22%3A%22-1%22%2C%22eval%22%3A%221%22%7D&pdp_npi=4%40dis%21USD%2117.35%2117.35%21%21%2117.35%2117.35%21%402103244617480549065328433e314e%2112000042593526663%21sea%21US%216221086412%21X&curPageLogUid=EwLTDPSoa9go&utparam-url=scene%3Asearch%7Cquery_from%3A
    * https://excelrc.com/products/betafpv-7x16mm-brushed-motors-19000kv-2cw-2ccw?variant=37534134403259&country=US¤cy=USD&gQT=1
    * https://speedyfpv.com/collections/brushed-motors
    * https://www.amazon.com/Coreless-Brushed-JST-1-25-Connector-Quadcopter/dp/B0CZ6WKVBK/ref=asc_df_B0CZ6WKVBK?mcid=258308b361a73b3ab94eb75c3df5d880&hvocijid=16122636454162648337-B0CZ6WKVBK-&hvexpln=73&tag=hyprod-20&linkCode=df0&hvadid=721245378154&hvpos=&hvnetw=g&hvrand=16122636454162648337&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9028276&hvtargid=pla-2281435178098&psc=1
    * https://www.amazon.com/YoungRC-8520-Coreless-Propeller-Quadcopter/dp/B0BV6P4XYX/ref=sr_1_2_sspa?crid=3AJ8O6AJVEB5X&dib=eyJ2IjoiMSJ9.CeWTFw3PXM5kx_Y3wdCzCsFy0RptOjYVXba-rfvDlQfvsx2SS8LzeHIXTSy1lG41YlPs53vfRKnFDeVboDM-zFeQcWEz3CDAOYMCOAwoPcElsX4uFftMqgQgeE0leK_TTJLvTej0bmtHV1M1z0n7008e91NEDQk8wLX-x64qGt9HwKx_juYs3sjEulBZRD1ARTD8o1p2fKzNhrsAy3NDkZL2iPY1sH5j02cuWQ_oPh2-lRrqHdBd-U9B3—yy_v-cQuJQKe_gynbgR_eZBlEEt8VdUATcRUv22JsLWLuzio.u-IRMGxt2WgfQ5QidPC23q36qNFRAg0-ucyN7Pd-z48&dib_tag=se&keywords=micro+motors&qid=1748056601&s=industrial&sprefix=micro+motors%2Cindustrial%2C121&sr=1-2-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1#averageCustomerReviewsAnchor
* Laser - $6 - ~10 grams
    * https://www.adafruit.com/product/1054
* 3d printing filament ~50 grams

## Motor Math

* Maximum of 150 grams with motors
* at least 75 g of thrust per motor
* 

## Resources

* https://files.seeedstudio.com/wiki/SeeedStudio-XIAO-ESP32S3/res/XIAO_ESP32S3_ExpBoard_v1.0_SCH.pdf
* https://www.unmannedsystemstechnology.com/feature/calculating-how-much-weight-a-drone-can-carry/
* https://www.digikey.com/en/maker/projects/a-step-by-step-guide-to-build-a-low-cost-drone-using-esp32/8afccd0690574bcebfa0d2ad6fd0a391


Measuring battery level: https://vivonomicon.com/2019/10/15/reading-battery-voltage-with-the-stm32s-adc/

OV5640 wiring: https://cdn-learn.adafruit.com/assets/assets/000/118/304/original/adafruit_products_cam_schem.png?1675865865
