If you wish to make a small digital clock, then you have come to the right place.

**AVERAGE COMPUTER SKILLS REQUIRED**
**SOLDERING IRON REQUIRED (and, of course, solder)**
**3D PRINTER REQUIRED**

As seen in the files, you can buy the KiCad circuit from PCBWay or whatever PCB manufacturer you use.

Now you need to buy this ESP32 (as I haven't tested whether other ESP32 boards fit).

**Amazon ESP32 link:**
https://www.amazon.co.uk/Development-XTVTX-NodeMCU-32-ESP-WROOM-compatible/dp/B0CJHR8SMK?pd_rd_w=aHLrJ&content-id=amzn1.sym.71304d4f-1a7f-49a0-917b-a8ecb707fc26&pf_rd_p=71304d4f-1a7f-49a0-917b-a8ecb707fc26&pf_rd_r=1H9C4TRN17KYBMAWZ3AB&pd_rd_wg=faznK&pd_rd_r=7f598b09-a3ce-46dc-ad21-ab1c6101a226&pd_rd_i=B0CJHR8SMK&psc=1&ref_=pd_basp_d_rpt_ba_s_3_pr_i

Image of said ESP32:

<img width="1254" height="792" alt="image" src="https://github.com/user-attachments/assets/5f94a72b-236d-4be3-bcb3-eff070eb0b26" />

Now you will need to buy some headers, which you will need to break to a size of 19 pins.

**Headers link:**
https://thepihut.com/products/female-2-54mm-header-packs?variant=55832553849217&country=GB&currency=GBP&utm_source=chatgpt.com

Now you will need the display.

**Display link:**
https://www.amazon.co.uk/dp/B07GTSLQXQ?ref_=ppx_hzsearch_conn_dt_b_fed_asin_title_1

Image of said display:

<img width="1221" height="744" alt="image" src="https://github.com/user-attachments/assets/96fb7639-b7a8-443a-8506-0226088a9acf" />

Now just get all of those parts, some female jumper wires to solder into the holes, and a couple of 220 Ω resistors to solder.

Connect the numbers to the display pins shown in this picture:

<img width="606" height="361" alt="image" src="https://github.com/user-attachments/assets/456b0e88-1943-46ec-bb9c-8752041dc9f1" />

| ESP32 Pin | Display Pin |
| --------- | ----------- |
| **5**     | D4          |
| **17**    | D3          |
| **16**    | D2          |
| **4**     | D1          |
| **32**    | DP          |
| **33**    | G           |
| **25**    | F           |
| **26**    | E           |
| **27**    | D           |
| **14**    | C           |
| **12**    | B           |
| **13**    | A           |

Now print the 3D print file, stick everything inside, and superglue or tape the lid on however you want.
