; @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
;
;    노기노기 패치 데이터 lv180
;
; @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

  ; 로고 없애기
  o_p_npdata_ver_chk  db 0FFh, 0D6h, 083h, 0F8h, 001h, 075h, 037h, 06Ah, 018h
  o_p_npmask_ver_chk  db    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_ver_chk  db 0FFh, 0D6h, 083h, 0F8h, 001h, 0EBh, 037h, 06Ah, 0FFh
  r_p_npmask_ver_chk  db    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_ver_chk  dd    9

  ; 12세 이용가 없애기
  o_p_npdata_no_logo_12t  db 0FFh, 0D6h, 083h, 0F8h, 004h, 075h, 039h, 06Ah, 014h
  o_p_npmask_no_logo_12t  db    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_no_logo_12t  db 0FFh, 0D6h, 083h, 0F8h, 004h, 0EBh, 039h, 06Ah, 014h
  r_p_npmask_no_logo_12t  db    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_no_logo_12t  dd    9

  ; 광고 없애기
  o_p_npdata_adv  db 074h, 029h, 08Dh, 04Dh, 0ECh
  o_p_npmask_adv  db    0,    0,    0,    0,    0
  r_p_npdata_adv  db 0EBh, 029h, 08Dh, 04Dh, 0ECh
  r_p_npmask_adv  db    0,    0,    0,    0,    0
  r_p_npcout_adv  dd    5

  ; 헤더 추가 더미
  o_p_header_dummy  db 04Dh, 05Ah, 090h, 000h, 003h, 000h, 000h, 000h, 004h, 000h, 000h, 000h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh

  o_p_header_mask   db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		
  r_p_header_dummy  db 04Dh, 05Ah, 090h, 000h, 003h, 000h, 000h, 000h, 004h, 000h, 000h, 000h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
        	 	 	 	 		db 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0E0h, 002h, 080h, 063h
										db 08Bh, 04Dh, 0ECh, 068h, 084h, 003h, 080h, 063h, 0FFh, 054h, 024h, 008h, 084h, 0C0h, 074h, 002h, 0EBh, 035h, 08Bh, 04Dh, 0ECh, 068h, 05Fh, 003h, 080h, 063h, 0FFh, 054h, 024h, 008h, 084h, 0C0h
										db 074h, 002h, 0EBh, 023h, 08Bh, 04Dh, 0ECh, 068h, 047h, 003h, 080h, 063h, 0E9h, 0ECh, 002h, 000h, 000h, 090h, 090h, 090h, 0B8h, 003h, 000h, 000h, 000h, 0B9h, 001h, 000h, 000h, 000h, 083h, 0F8h
										db 003h, 08Bh, 04Dh, 0ECh, 0C2h, 008h, 000h, 0B8h, 004h, 000h, 000h, 000h, 0B9h, 001h, 000h, 000h, 000h, 083h, 0F8h, 003h, 0C2h, 008h, 000h, 08Bh, 044h, 024h, 008h, 0B9h, 000h, 000h, 000h, 000h
										db 084h, 0C0h, 0C2h, 008h, 000h, 000h, 000h, 02Fh, 000h, 063h, 000h, 061h, 000h, 06Dh, 000h, 070h, 000h, 05Fh, 000h, 06Bh, 000h, 069h, 000h, 074h, 000h, 02Fh, 000h, 000h, 000h, 000h, 000h, 02Fh
										db 000h, 061h, 000h, 064h, 000h, 076h, 000h, 065h, 000h, 072h, 000h, 074h, 000h, 069h, 000h, 073h, 000h, 065h, 000h, 05Fh, 000h, 062h, 000h, 06Fh, 000h, 061h, 000h, 072h, 000h, 064h, 000h, 02Fh
										db 000h, 000h, 000h, 000h, 02Fh, 000h, 073h, 000h, 068h, 000h, 061h, 000h, 064h, 000h, 06Fh, 000h, 077h, 000h, 05Fh, 000h, 06Dh, 000h, 069h, 000h, 073h, 000h, 073h, 000h, 069h, 000h, 06Fh, 000h
										db 06Eh, 000h, 05Fh, 000h, 062h, 000h, 06Fh, 000h, 061h, 000h, 072h, 000h, 064h, 000h, 02Fh, 000h, 000h, 000h, 000h, 0B7h, 003h, 080h, 063h, 08Bh, 097h, 0ACh, 000h, 000h, 000h, 083h, 0FAh, 001h
										db 074h, 023h, 090h, 080h, 078h, 049h, 001h, 074h, 012h, 083h, 0FAh, 002h, 074h, 00Dh, 0B8h, 002h, 000h, 000h, 000h, 0BAh, 002h, 004h, 080h, 063h, 0EBh, 008h, 0C3h, 08Bh, 0C2h, 0BAh, 01Bh, 004h
										db 080h, 063h, 0EBh, 00Bh, 0C3h, 083h, 0FAh, 001h, 08Bh, 090h, 0BCh, 000h, 000h, 000h, 0C3h, 083h, 0F8h, 001h, 0C3h, 0F7h, 003h, 080h, 063h, 089h, 045h, 0F0h, 03Bh, 0C7h, 089h, 07Dh, 0FCh, 0C3h
										db 000h, 000h, 00Ah, 000h, 00Ah, 000h, 03Ch, 000h, 063h, 000h, 06Fh, 000h, 06Ch, 000h, 06Fh, 000h, 072h, 000h, 03Dh, 000h, 031h, 000h, 03Eh, 000h, 000h, 000h, 000h, 00Ah, 000h, 00Ah, 000h, 03Ch
										db 000h, 063h, 000h, 06Fh, 000h, 06Ch, 000h, 06Fh, 000h, 072h, 000h, 03Dh, 000h, 030h, 000h, 03Eh, 000h, 000h, 000h, 000h, 038h, 004h, 080h, 063h, 08Bh, 00Ch, 024h, 052h, 050h, 051h, 08Bh, 0CFh
										db 0FFh, 0D3h, 059h, 052h, 050h, 08Bh, 0D1h, 08Bh, 0CEh, 0FFh, 0E2h, 000h, 000h, 044h, 000h, 075h, 000h, 072h, 000h, 061h, 000h, 062h, 000h, 069h, 000h, 06Ch, 000h, 069h, 000h, 074h, 000h, 079h
										db 000h, 020h, 000h, 07Bh, 000h, 031h, 000h, 07Dh, 000h, 02Fh, 000h, 07Bh, 000h, 033h, 000h, 07Dh, 000h, 020h, 000h, 028h, 000h, 07Bh, 000h, 030h, 000h, 07Dh, 000h, 02Fh, 000h, 07Bh, 000h, 032h
										db 000h, 07Dh, 000h, 029h, 000h, 000h, 000h, 000h, 08Ch, 004h, 080h, 063h, 0B8h, 000h, 000h, 000h, 000h, 0FFh, 012h, 08Bh, 0CDh, 074h, 00Dh, 0FFh, 052h, 004h, 08Bh, 0CDh, 074h, 004h, 0B0h, 000h
										db 0EBh, 002h, 0B0h, 001h, 084h, 0C0h, 0BAh, 000h, 000h, 000h, 000h, 0C3h, 0B1h, 004h, 080h, 063h, 000h, 089h, 045h, 0F0h, 03Bh, 0C7h, 089h, 07Dh, 0FCh, 0C3h, 0BEh, 004h, 080h, 063h, 083h, 0C4h
										db 004h, 0FFh, 0D6h, 08Bh, 0C8h, 0FFh, 0D6h, 08Bh, 0C8h, 0FFh, 0D6h, 08Bh, 0C8h, 0FFh, 0D6h, 08Bh, 0C8h, 05Ah, 083h, 0C2h, 00Dh, 0FFh, 0E2h, 0DBh, 004h, 080h, 063h, 08Bh, 044h, 0E4h, 004h, 088h
										db 046h, 011h, 08Bh, 045h, 010h, 089h, 046h, 014h, 08Ah, 045h, 014h, 088h, 046h, 018h, 081h, 07Eh, 00Ch, 078h, 056h, 034h, 012h, 075h, 007h, 0C7h, 046h, 00Ch, 0DBh, 0FFh, 0FFh, 0FFh, 0C3h, 003h
										db 005h, 080h, 063h, 08Bh, 004h, 0E4h, 083h, 0C4h, 004h, 081h, 0FFh, 078h, 056h, 034h, 012h, 074h, 011h, 081h, 0FBh, 078h, 056h, 034h, 012h, 074h, 00Eh, 085h, 0C9h, 074h, 014h, 0FFh, 075h, 008h
										db 0EBh, 00Ah, 083h, 0FFh, 000h, 0EBh, 0F6h, 083h, 0FBh, 000h, 0EBh, 0F1h, 0BAh, 033h, 005h, 080h, 063h, 0FFh, 0E0h, 0C6h, 046h, 008h, 001h, 081h, 0FFh, 078h, 056h, 034h, 012h, 074h, 006h, 081h
										db 0FBh, 078h, 056h, 034h, 012h, 0BAh, 000h, 014h, 000h, 000h, 0C3h, 000h, 000h, 000h, 000h, 000h, 081h, 07Eh, 058h, 000h, 0CCh, 099h, 0FFh, 0C7h, 046h, 058h, 0FFh, 0CCh, 000h, 0FFh, 0C7h, 046h
										db 05Ch, 0FFh, 0CCh, 000h, 000h, 053h, 00Fh, 084h, 089h, 000h, 000h, 000h, 08Bh, 0C3h, 0BBh, 000h, 000h, 000h, 000h, 083h, 0E8h, 018h, 08Bh, 0CFh, 0FFh, 0D0h, 085h, 0C0h, 074h, 00Eh, 0C7h, 046h
										db 058h, 0CBh, 0C0h, 0FFh, 0FFh, 0C7h, 046h, 05Ch, 0CBh, 0C0h, 0FFh, 000h, 058h, 050h, 083h, 0E8h, 00Ch, 08Bh, 0CFh, 0FFh, 0D0h, 085h, 0C0h, 074h, 00Eh, 0C7h, 046h, 058h, 000h, 0CCh, 000h, 0FFh
										db 0C7h, 046h, 05Ch, 000h, 0CCh, 000h, 000h, 058h, 050h, 083h, 0C0h, 03Ch, 08Bh, 0CFh, 0FFh, 0D0h, 085h, 0C0h, 074h, 00Eh, 0C7h, 046h, 058h, 000h, 0CCh, 0FFh, 0FFh, 0C7h, 046h, 05Ch, 000h, 0CCh
										db 0FFh, 000h, 058h, 050h, 08Bh, 0CFh, 0FFh, 0D0h, 085h, 0C0h, 074h, 029h, 0C7h, 046h, 058h, 000h, 066h, 0FFh, 0FFh, 0C7h, 046h, 05Ch, 000h, 033h, 099h, 000h, 058h, 050h, 083h, 0C0h, 018h, 08Bh
										db 0CFh, 0FFh, 0D0h, 085h, 0C0h, 075h, 00Eh, 0C7h, 046h, 058h, 0FFh, 062h, 03Eh, 0FFh, 0C7h, 046h, 05Ch, 0FFh, 062h, 03Eh, 000h, 058h, 08Bh, 0CFh, 0FFh, 0D0h, 085h, 0C0h, 0C3h, 0FFh, 054h, 024h
										db 008h, 084h, 0C0h, 00Fh, 085h, 00Bh, 0FDh, 0FFh, 0FFh, 08Bh, 04Dh, 0ECh, 068h, 078h, 006h, 080h, 063h, 0FFh, 054h, 024h, 008h, 084h, 0C0h, 00Fh, 085h, 00Ah, 0FDh, 0FFh, 0FFh, 08Bh, 04Dh, 0ECh
										db 068h, 096h, 006h, 080h, 063h, 0FFh, 054h, 024h, 008h, 084h, 0C0h, 00Fh, 085h, 0F6h, 0FCh, 0FFh, 0FFh, 08Bh, 04Dh, 0ECh, 068h, 0B2h, 006h, 080h, 063h, 0FFh, 054h, 024h, 008h, 084h, 0C0h, 00Fh
										db 085h, 0E2h, 0FCh, 0FFh, 0FFh, 08Bh, 04Dh, 0ECh, 068h, 0D2h, 006h, 080h, 063h, 0FFh, 054h, 024h, 008h, 084h, 0C0h, 00Fh, 085h, 0CEh, 0FCh, 0FFh, 0FFh, 08Bh, 04Dh, 0ECh, 068h, 004h, 007h, 080h
										db 063h, 0FFh, 054h, 024h, 008h, 084h, 0C0h, 00Fh, 085h, 0BAh, 0FCh, 0FFh, 0FFh, 0E9h, 0C5h, 0FCh, 0FFh, 0FFh, 000h, 000h, 000h, 000h, 000h, 000h, 02Fh, 000h, 063h, 000h, 061h, 000h, 073h, 000h
										db 074h, 000h, 06Ch, 000h, 065h, 000h, 05Fh, 000h, 069h, 000h, 06Eh, 000h, 066h, 000h, 06Fh, 000h, 02Fh, 000h, 000h, 000h, 000h, 000h, 02Fh, 000h, 068h, 000h, 06Fh, 000h, 075h, 000h, 073h, 000h
										db 065h, 000h, 05Fh, 000h, 069h, 000h, 06Eh, 000h, 066h, 000h, 06Fh, 000h, 02Fh, 000h, 000h, 000h, 000h, 000h, 02Fh, 000h, 068h, 000h, 06Fh, 000h, 075h, 000h, 073h, 000h, 069h, 000h, 06Eh, 000h
										db 067h, 000h, 05Fh, 000h, 069h, 000h, 06Eh, 000h, 066h, 000h, 06Fh, 000h, 02Fh, 000h, 000h, 000h, 000h, 000h, 02Fh, 000h, 064h, 000h, 075h, 000h, 06Eh, 000h, 067h, 000h, 065h, 000h, 06Fh, 000h
										db 06Eh, 000h, 05Fh, 000h, 072h, 000h, 061h, 000h, 06Eh, 000h, 06Bh, 000h, 069h, 000h, 06Eh, 000h, 067h, 000h, 05Fh, 000h, 062h, 000h, 06Fh, 000h, 061h, 000h, 072h, 000h, 064h, 000h, 02Fh, 000h
										db 000h, 000h, 000h, 000h, 02Fh, 000h, 070h, 000h, 061h, 000h, 072h, 000h, 074h, 000h, 079h, 000h, 05Fh, 000h, 062h, 000h, 06Fh, 000h, 061h, 000h, 072h, 000h, 064h, 000h, 02Fh, 000h, 000h, 000h
										db 0D9h, 098h, 0D0h, 000h, 000h, 000h, 08Bh, 046h, 064h, 0D9h, 005h, 030h, 007h, 080h, 063h, 0C3h, 000h, 080h, 0BBh, 044h, 000h, 0C3h, 000h, 000h, 08Bh, 0CFh, 050h, 053h, 0FFh, 0D3h, 08Bh, 0CFh
										db 052h, 083h, 0C3h, 012h, 0FFh, 0D3h, 052h, 058h, 05Ah, 05Bh, 03Bh, 0C2h, 058h, 075h, 00Ah, 083h, 0F8h, 000h, 074h, 005h, 090h, 090h, 090h, 0EBh, 011h, 083h, 0F8h, 010h, 077h, 008h, 0B8h, 00Fh
										db 000h, 000h, 000h, 083h, 0F8h, 010h, 08Bh, 0CFh, 0EBh, 02Ch, 0EBh, 032h, 0EBh, 01Ah, 0EBh, 0F6h, 000h, 000h, 000h, 03Ch, 000h, 063h, 000h, 06Fh, 000h, 06Ch, 000h, 06Fh, 000h, 072h, 000h, 03Dh
										db 000h, 033h, 000h, 03Eh, 000h, 000h, 000h, 000h, 068h, 073h, 007h, 080h, 063h, 08Bh, 0CFh, 0BAh, 000h, 014h, 000h, 000h, 0FFh, 0E0h, 08Bh, 0CFh, 0BAh, 000h, 014h, 000h, 000h, 0C3h, 0B8h, 010h
										db 000h, 000h, 000h, 083h, 0F8h, 010h, 058h, 0EBh, 0C3h, 090h, 000h, 000h, 065h, 000h, 06Eh, 000h, 065h, 000h, 06Dh, 000h, 079h, 000h, 07Ch, 000h, 070h, 000h, 072h, 000h, 06Fh, 000h, 070h, 000h
										db 000h, 000h, 00Ah, 00Bh, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
										
  r_p_header_mask   db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 000h, 000h, 000h, 000h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h
        	 	 	 	 		db 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 001h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
        	 	 	 	 		
  r_p_header_cout   dd 2016

; ######################################################################################################################################################################
;
;  //  별  짓  하  기  //
;
; 별짓하기 - 마우스 금지 해제
  o_p_npdata_st_mouse_notouch  db 083h, 078h, 04Ch, 000h, 074h, 019h
  o_p_npmask_st_mouse_notouch  db    0,    0,    0,    0,    0,    0
  r_p_npdata_st_mouse_notouch  db 083h, 078h, 04Ch, 000h, 0EBh, 019h
  r_p_npmask_st_mouse_notouch  db    0,    0,    0,    0,    0,    0
  r_p_npcout_st_mouse_notouch  dd    6

  ; 별짓하기 - 인터페이스 락 해제
  o_p_npdata_st_ui_unlock  db 080h, 07Ch, 024h, 004h, 000h, 056h, 057h
  o_p_npmask_st_ui_unlock  db    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_st_ui_unlock  db 0C2h, 008h, 000h, 090h, 090h, 056h, 057h
  r_p_npmask_st_ui_unlock  db    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_st_ui_unlock  dd    7

  ; 별짓하기 - 아이템 드롭커서 표시 1
  o_p_npdata_st_drop_cursor1  db 084h, 0C0h, 074h, 004h, 033h, 0C0h, 0EBh, 078h
  o_p_npmask_st_drop_cursor1  db    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_st_drop_cursor1  db 084h, 0C0h, 0EBh, 004h, 033h, 0C0h, 0EBh, 078h
  r_p_npmask_st_drop_cursor1  db    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_st_drop_cursor1  dd    8

  ; 별짓하기 - 아이템 드롭커서 표시 2
  o_p_npdata_st_drop_cursor2  db 084h, 0C0h, 074h, 004h, 033h, 0C0h, 0EBh, 043h
  o_p_npmask_st_drop_cursor2  db    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_st_drop_cursor2  db 084h, 0C0h, 0EBh, 004h, 033h, 0C0h, 0EBh, 043h
  r_p_npmask_st_drop_cursor2  db    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_st_drop_cursor2  dd    8

  ; 별짓하기 - 드롭된 아이템 줍기 
  o_p_npdata_st_drop_item_keep  db 084h, 0C0h, 075h, 01Ah, 06Ah, 000h, 053h, 055h
  o_p_npmask_st_drop_item_keep  db    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_st_drop_item_keep  db 084h, 0C0h, 070h, 01Ah, 06Ah, 000h, 053h, 055h
  r_p_npmask_st_drop_item_keep  db    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_st_drop_item_keep  dd    8

  ; 별짓하기 - 죽었을때 아이템 우클릭 팝업 활성화
  o_p_npdata_st_knockdown_item_popup_enable1  db 0EBh, 055h, 08Bh, 0CEh, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 00Fh, 085h
  o_p_npmask_st_knockdown_item_popup_enable1  db    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0
  r_p_npdata_st_knockdown_item_popup_enable1  db 0EBh, 055h, 08Bh, 0CEh, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 00Fh, 080h
  r_p_npmask_st_knockdown_item_popup_enable1  db    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0
  r_p_npcout_st_knockdown_item_popup_enable1  dd   13

  ; 별짓하기 - 죽었을때 캐릭터 우클릭 팝업 활성화
  o_p_npdata_st_knockdown_item_popup_enable2  db 08Bh, 0CEh, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 00Fh, 085h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0CBh
  o_p_npmask_st_knockdown_item_popup_enable2  db    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0
  r_p_npdata_st_knockdown_item_popup_enable2  db 08Bh, 0CEh, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 00Fh, 080h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0CBh 
  r_p_npmask_st_knockdown_item_popup_enable2  db    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0
  r_p_npcout_st_knockdown_item_popup_enable2  dd   17

  ; 별짓하기 - 아이템 우클릭 팝업 드롭 메뉴 활성화 [ALL]
  o_p_npdata_st_item_right_popup_drop_menu_enable  db 084h, 0C0h, 075h, 03Ch, 08Bh, 04Dh, 0E8h
  o_p_npmask_st_item_right_popup_drop_menu_enable  db    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_st_item_right_popup_drop_menu_enable  db 084h, 0C0h, 070h, 03Ch, 08Bh, 04Dh, 0E8h
  r_p_npmask_st_item_right_popup_drop_menu_enable  db    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_st_item_right_popup_drop_menu_enable  dd    7

  ; 별짓하기 - 죽었을때 오른쪽 팝업 클릭하기
  o_p_npdata_st_knockdown_right_popup_click  db 083h, 078h, 04Ch, 009h, 074h, 007h, 033h, 0C0h, 0E9h
  o_p_npmask_st_knockdown_right_popup_click  db    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_st_knockdown_right_popup_click  db 083h, 078h, 04Ch, 009h, 0EBh, 007h, 033h, 0C0h, 0E9h
  r_p_npmask_st_knockdown_right_popup_click  db    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_st_knockdown_right_popup_click  dd    9

  ; 별짓하기 - 드롭 가능하게 하기
  o_p_npdata_st_item_drop_enable  db 0FFh, 060h, 050h, 056h, 08Bh, 0F1h, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 074h, 004h, 032h, 0C0h, 05Eh, 0C3h, 08Bh, 08Eh
  o_p_npmask_st_item_drop_enable  db    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_st_item_drop_enable  db 0FFh, 060h, 050h, 056h, 08Bh, 0F1h, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 0EBh, 004h, 032h, 0C0h, 05Eh, 0C3h, 08Bh, 08Eh
  r_p_npmask_st_item_drop_enable  db    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_st_item_drop_enable  dd   21

  ; 죽었을때 별짓하기 스탠다드 1
  o_s_npdata_st1  db 084h, 0C0h, 074h, 013h, 08Bh, 006h, 08Bh, 0CEh, 0FFh, 090h, 080h, 000h, 000h, 000h, 08Bh, 010h, 06Ah, 000h, 08Bh, 0C8h, 0FFh, 052h, 074h
  o_s_npmask_st1  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_s_npdata_st1  db 084h, 0C0h, 0EBh, 013h, 08Bh, 006h, 08Bh, 0CEh, 0FFh, 090h, 080h, 000h, 000h, 000h, 08Bh, 010h, 06Ah, 000h, 08Bh, 0C8h, 0FFh, 052h, 074h
  r_s_npmask_st1  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_s_npcout_st1  dd   23

  ; 죽었을때 별짓하기 스탠다드 2
  o_s_npdata_st2  db 084h, 0C0h, 074h, 014h, 08Bh, 006h, 08Bh, 0CEh
  o_s_npmask_st2  db    0,    0,    0,    0,    0,    0,    0,    0
  r_s_npdata_st2  db 084h, 0C0h, 0EBh, 014h, 08Bh, 006h, 08Bh, 0CEh
  r_s_npmask_st2  db    0,    0,    0,    0,    0,    0,    0,    0
  r_s_npcout_st2  dd    8

  ; 죽은척일때 별짓하기
  o_s_npdata_st_fake  db 0F6h, 0C3h, 008h, 074h, 008h, 057h, 08Bh, 0CEh, 0E8h
  o_s_npmask_st_fake  db    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_s_npdata_st_fake  db 05Fh, 08Bh, 0C6h, 05Eh, 05Bh, 0C2h, 010h, 000h, 090h
  r_s_npmask_st_fake  db    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_s_npcout_st_fake  dd    9

  ; 행동불능 스킬사용
  o_p_npdata_knockdown_skill_usable  db 083h, 078h, 04Ch, 000h, 074h, 02Ah, 0E8h
  o_p_npmask_knockdown_skill_usable  db    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_knockdown_skill_usable  db 083h, 078h, 04Ch, 000h, 0EBh, 02Ah, 0E8h
  r_p_npmask_knockdown_skill_usable  db    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_knockdown_skill_usable  dd    7

  ; 행동불능일때 하이드 가능
  o_p_npdata_knockdown_hide_usable  db 083h, 078h, 04Ch, 001h, 074h, 00Bh, 0E8h
  o_p_npmask_knockdown_hide_usable  db    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_knockdown_hide_usable  db 083h, 078h, 04Ch, 001h, 074h, 000h, 0E8h
  r_p_npmask_knockdown_hide_usable  db    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_knockdown_hide_usable  dd    7

; ######################################################################################################################################################################

  ; 현재채널 이동
  o_p_npdata_selfcl_move  db 084h, 0C0h, 059h, 059h, 00Fh, 084h, 08Ch, 000h ,000h, 000h, 068h
  o_p_npmask_selfcl_move  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_selfcl_move  db 084h, 0C0h, 059h, 059h, 00Fh, 081h, 08Ch, 000h, 000h, 000h, 068h
  r_p_npmask_selfcl_move  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_selfcl_move  dd   11

  ; 모든 타이틀 보기
  o_p_npdata_all_title_view  db 083h, 0F8h, 001h, 07Eh, 056h, 083h, 0F8h, 002h
  o_p_npmask_all_title_view  db    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_all_title_view  db 083h, 0F8h, 001h, 0EBh, 056h, 083h, 0F8h, 002h
  r_p_npmask_all_title_view  db    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_all_title_view  dd    8

  ; 하이드 캐릭터 보기
  o_p_npdata_hide_chr_view  db 084h, 0C0h, 074h, 008h, 06Ah, 002h, 058h
  o_p_npmask_hide_chr_view  db    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_hide_chr_view  db 084h, 0C0h, 070h, 008h, 06Ah, 002h, 058h
  r_p_npmask_hide_chr_view  db    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_hide_chr_view  dd    7

  ; NPC 장비보기
  o_p_npdata_npc_equip_view  db 084h, 0C0h, 075h, 056h, 06Ah, 028h
  o_p_npmask_npc_equip_view  db    0,    0,    0,    0,    0,    0
  r_p_npdata_npc_equip_view  db 084h, 0C0h, 070h, 056h, 06Ah, 028h
  r_p_npmask_npc_equip_view  db    0,    0,    0,    0,    0,    0
  r_p_npcout_npc_equip_view  dd    6

  ; 개인상점 멀리서 열기
  o_p_npdata_psshop_far_open  db 0F6h, 0C4h, 001h, 075h, 015h, 0FFh, 075h, 014h
  o_p_npmask_psshop_far_open  db    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_psshop_far_open  db 0F6h, 0C4h, 001h, 070h, 015h, 0FFh, 075h, 014h
  r_p_npmask_psshop_far_open  db    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_psshop_far_open  dd    8

  ; 컷신 빠르게 스킵
  o_p_npdata_cutscene_fastskip  db 081h, 0C1h, 0D0h, 007h, 000h, 000h, 03Bh, 04Fh, 00Ch
  o_p_npmask_cutscene_fastskip  db    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_cutscene_fastskip  db 083h, 0C1h, 000h, 090h, 090h, 090h, 03Bh, 04Fh, 00Ch
  r_p_npmask_cutscene_fastskip  db    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_cutscene_fastskip  dd    9

  ; 가방 항상 열기
  o_p_npdata_premium_bag  db 084h, 0C0h, 075h, 03Fh, 0FFh, 015h
  o_p_npmask_premium_bag  db    0,    0,    0,    0,    0,    0
  r_p_npdata_premium_bag  db 084h, 0C0h, 0EBh, 03Fh, 0FFh, 015h
  r_p_npmask_premium_bag  db    0,    0,    0,    0,    0,    0
  r_p_npcout_premium_bag  dd    6

  ; 가방 항상 열기 2
  o_p_npdata_premium_bag2  db 063h, 084h, 0C0h, 075h, 02Bh
  o_p_npmask_premium_bag2  db    0,    0,    0,    0,    0
  r_p_npdata_premium_bag2  db 063h, 084h, 0C0h, 0EBh, 02Bh
  r_p_npmask_premium_bag2  db    0,    0,    0,    0,    0
  r_p_npcout_premium_bag2  dd    5

  ; 파티 모집창 지속
  o_p_npdata_party_invite_always  db 03Bh, 046h, 00Ch, 076h, 05Eh, 08Bh, 04Eh, 004h
  o_p_npmask_party_invite_always  db    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_party_invite_always  db 03Bh, 046h, 00Ch, 0EBh, 05Eh, 08Bh, 04Eh, 004h
  r_p_npmask_party_invite_always  db    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_party_invite_always  dd    8

  ; 변신 후에도 PVP 해제 가능
  o_p_npdata_t_after_pvp_disable  db 084h, 0C0h, 00Fh, 084h, 080h, 000h, 000h, 000h, 068h, 0FFh, 0FFh, 0FFh, 0FFh, 08Dh, 04Dh, 010h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh
  o_p_npmask_t_after_pvp_disable  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    1,    1,    1,    1,    1,    1,    1,    1
  r_p_npdata_t_after_pvp_disable  db 0EBh, 006h, 00Fh, 081h, 080h, 000h, 000h, 000h, 03Ch, 001h, 074h, 008h, 039h, 05Eh, 004h, 00Fh, 095h, 0C0h, 0EBh, 0EEh, 0B0h, 000h, 0EBh, 0EAh
  r_p_npmask_t_after_pvp_disable  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_t_after_pvp_disable  dd   24

  ; 변신 후에도 PVP 해제 가능 2
  o_p_npdata_t_after_pvp_disable2  db 039h, 05Eh, 004h, 08Bh, 04Dh, 0F0h, 00Fh, 095h, 0C0h, 053h, 050h
  o_p_npmask_t_after_pvp_disable2  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_t_after_pvp_disable2  db 090h, 090h, 090h, 08Bh, 04Dh, 0F0h, 090h, 090h, 090h, 053h, 050h
  r_p_npmask_t_after_pvp_disable2  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_t_after_pvp_disable2  dd   11

  ; 채널 상태 관계없이 접속
  o_p_npdata_channel_ignore_connect  db 063h, 084h, 0C0h, 00Fh, 085h, 018h, 001h, 000h, 000h
  o_p_npmask_channel_ignore_connect  db    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_channel_ignore_connect  db 063h, 084h, 0C0h, 00Fh, 081h, 018h, 001h, 000h, 000h
  r_p_npmask_channel_ignore_connect  db    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_channel_ignore_connect  dd    9

  ; 채널 상태 관계없이 접속 2
  o_p_npdata_channel_ignore_connect2  db 089h, 075h, 0DCh, 080h, 07Dh, 008h, 000h, 00Fh, 084h
  o_p_npmask_channel_ignore_connect2  db    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_channel_ignore_connect2  db 089h, 075h, 0DCh, 080h, 07Dh, 008h, 000h, 00Fh, 081h
  r_p_npmask_channel_ignore_connect2  db    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_channel_ignore_connect2  dd    9

  ; ALT 눌렀을 때 시야에 있는 모든 이름표 표시
  o_p_npdata_all_name_tag_visible  db 066h, 089h, 043h, 058h, 0DFh, 0E0h, 0F6h, 0C4h, 041h, 00Fh, 085h
  o_p_npmask_all_name_tag_visible  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_all_name_tag_visible  db 066h, 089h, 043h, 058h, 0DFh, 0E0h, 0F6h, 0C4h, 041h, 00Fh, 080h
  r_p_npmask_all_name_tag_visible  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_all_name_tag_visible  dd   11

  ; 비행 펫 낙하 고도 제한 없애기
  o_p_npdata_no_fallen_warning  db 0DCh, 05Dh, 050h, 0DFh, 0E0h, 0F6h, 0C4h, 041h, 00Fh, 08Ah
  o_p_npmask_no_fallen_warning  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_no_fallen_warning  db 0DCh, 05Dh, 050h, 0DFh, 0E0h, 0F6h, 0C4h, 041h, 00Fh, 081h
  r_p_npmask_no_fallen_warning  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_no_fallen_warning  dd   10

  ; 표지판 멀리서도 보기
  o_p_npdata_farshow_sign_post  db 0DFh, 0E0h, 0F6h, 0C4h, 041h, 07Ah, 00Bh, 08Dh, 045h, 0F0h, 050h, 08Dh, 04Dh, 0E8h
  o_p_npmask_farshow_sign_post  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_farshow_sign_post  db 0DFh, 0E0h, 0F6h, 0C4h, 041h, 070h, 00Bh, 08Dh, 045h, 0F0h, 050h, 08Dh, 04Dh, 0E8h
  r_p_npmask_farshow_sign_post  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_farshow_sign_post  dd   14

; #######################################################################################################################################################################################################################################
;
;  //  골  렘  연  성  S t u f f  //
;
  ; 골렘 캐릭터창 오픈
  o_p_npdata_recalled_chrwin_enable  db 08Bh, 0F0h, 085h, 0F6h, 074h, 0FFh, 08Bh, 08Eh, 0FFh, 000h, 000h, 000h, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 074h, 0FFh, 0FFh, 015h
  o_p_npmask_recalled_chrwin_enable  db    0,    0,    0,    0,    0,    1,    0,    0,    1,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    1,    0,    0
  r_p_npdata_recalled_chrwin_enable  db 08Bh, 0F0h, 085h, 0F6h, 074h, 0FFh, 08Bh, 08Eh, 0FFh, 000h, 000h, 000h, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 0EBh, 0FFh, 0FFh, 015h
  r_p_npmask_recalled_chrwin_enable  db    0,    0,    0,    0,    0,    1,    0,    0,    1,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    1,    0,    0
  r_p_npcout_recalled_chrwin_enable  dd   24

  ; 골렘 지도 경로 찍기
  o_p_npdata_recalled_minimap_move  db 084h, 0C0h, 00Fh, 085h, 0FFh, 0FFh, 0FFh, 0FFh, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 080h, 0B8h, 09Ch, 000h, 000h, 000h, 000h
  o_p_npmask_recalled_minimap_move  db    0,    0,    0,    0,    1,    1,    1,    1,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_recalled_minimap_move  db 084h, 0C0h, 00Fh, 080h, 0FFh, 0FFh, 0FFh, 0FFh, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 080h, 0B8h, 09Ch, 000h, 000h, 000h, 000h
  r_p_npmask_recalled_minimap_move  db    0,    0,    0,    0,    1,    1,    1,    1,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_recalled_minimap_move  dd   20

  ; 골렘 프롭 치기
  o_p_npdata_recalled_prop_touch  db 084h, 0C0h, 00Fh, 085h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 075h, 00Ch, 0FFh, 075h, 008h, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0C8h, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 085h, 0C0h, 089h, 045h, 0F0h, 00Fh, 084h
  o_p_npmask_recalled_prop_touch  db    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_recalled_prop_touch  db 084h, 0C0h, 00Fh, 080h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 075h, 00Ch, 0FFh, 075h, 008h, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0C8h, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 085h, 0C0h, 089h, 045h, 0F0h, 00Fh, 084h
  r_p_npmask_recalled_prop_touch  db    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_recalled_prop_touch  dd   33

  ; 골렘 기타 프롭 사용 가능
  o_p_npdata_recalled_prop_usable  db 084h, 0C0h, 00Fh, 085h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 045h, 00Ch, 0FFh, 075h, 00Ch, 0C1h, 0E8h, 010h, 083h, 0F8h, 010h, 0FFh, 075h, 008h, 075h, 00Ch
  o_p_npmask_recalled_prop_usable  db    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_recalled_prop_usable  db 084h, 0C0h, 00Fh, 080h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 045h, 00Ch, 0FFh, 075h, 00Ch, 0C1h, 0E8h, 010h, 083h, 0F8h, 010h, 0FFh, 075h, 008h, 075h, 00Ch
  r_p_npmask_recalled_prop_usable  db    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_recalled_prop_usable  dd   25

  ; 골렘 컨트롤 상태에서 채팅/귓속말/길드채팅 1
  o_p_npdata_golemtalk1		db 08Bh, 088h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 00Fh, 084h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 03Dh, 0FFh, 0FFh, 0FFh, 0FFh, 068h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0D7h
  o_p_npmask_golemtalk1		db    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    1,    1,    1,    1,    0,    0
  r_p_npdata_golemtalk1		db 08Bh, 088h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 00Fh, 081h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 03Dh, 0FFh, 0FFh, 0FFh, 0FFh, 068h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0D7h
  r_p_npmask_golemtalk1		db    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    1,    1,    1,    1,    0,    0
  r_p_npcout_golemtalk1   dd   33

  ; 골렘 컨트롤 상태에서 채팅/귓속말/길드채팅 2
  o_p_npdata_golemtalk2		db 00Fh, 084h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 088h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 075h, 0FFh, 08Bh, 05Dh, 0FFh, 08Bh, 035h
  o_p_npmask_golemtalk2		db    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    0,    1,    0,    0,    1,    0,    0
  r_p_npdata_golemtalk2		db 00Fh, 084h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 088h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 070h, 0FFh, 08Bh, 05Dh, 0FFh, 08Bh, 035h
  r_p_npmask_golemtalk2		db    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    0,    1,    0,    0,    1,    0,    0
  r_p_npcout_golemtalk2   dd   27

  ; 골렘 사정거리 제어권 유지 1
  o_p_npdata_golem_cont1  db 08Bh, 0F8h, 085h, 0FFh, 059h, 059h, 089h, 07Dh, 0F0h, 00Fh, 084h
  o_p_npmask_golem_cont1  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_golem_cont1  db 08Bh, 0F8h, 085h, 0FFh, 059h, 059h, 089h, 07Dh, 0F0h, 00Fh, 081h
  r_p_npmask_golem_cont1  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_golem_cont1  dd   11
  
  ; 골렘 사정거리 제어권 유지 2
  o_p_npdata_golem_cont2  db 066h, 03Dh, 060h, 0C3h, 074h, 0FFh, 08Bh, 006h, 068h, 061h, 0C3h, 000h, 000h, 08Bh, 0FFh, 0FFh, 050h, 060h, 08Bh, 0C8h, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 075h, 0FFh, 08Bh, 08Eh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 075h
  o_p_npmask_golem_cont2  db    0,    0,    0,    0,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    1,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    1,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    0
  r_p_npdata_golem_cont2  db 066h, 03Dh, 060h, 0C3h, 070h, 0FFh, 08Bh, 006h, 068h, 061h, 0C3h, 000h, 000h, 08Bh, 0FFh, 0FFh, 050h, 060h, 08Bh, 0C8h, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 070h, 0FFh, 08Bh, 08Eh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 070h
  r_p_npmask_golem_cont2  db    0,    0,    0,    0,    0,    1,    0,    0,    0,    0,    0,    0,    0,    0,    1,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    1,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    0
  r_p_npcout_golem_cont2  dd   45
  

; #######################################################################################################################################################################################################################################

  ; 프롭칠때 공격모드 전환 안하게 하기
  o_p_npdata_prop_touch_not_mode_change  db 03Bh, 0C3h, 00Fh, 085h, 028h, 001h, 000h, 000h, 0FFh, 075h, 0F0h, 057h, 0FFh, 015h
  o_p_npmask_prop_touch_not_mode_change  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_prop_touch_not_mode_change  db 03Bh, 0C3h, 00Fh, 080h, 028h, 001h, 000h, 000h, 0FFh, 075h, 0F0h, 057h, 0FFh, 015h
  r_p_npmask_prop_touch_not_mode_change  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_prop_touch_not_mode_change  dd   14

  ; 스프라이트 모든 명령 사용 가능
  o_p_npdata_sprit_all_cmd_enable  db 08Dh, 04Dh, 0D4h, 0FFh, 0D6h, 080h, 07Dh, 0F3h, 000h, 00Fh, 084h
  o_p_npmask_sprit_all_cmd_enable  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_sprit_all_cmd_enable  db 08Dh, 04Dh, 0D4h, 0FFh, 0D6h, 080h, 07Dh, 0F3h, 000h, 00Fh, 081h
  r_p_npmask_sprit_all_cmd_enable  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_sprit_all_cmd_enable  dd   11

  ; 애완동물 소환 지연시 스페이스바로 움직이기 [ALL]
  o_p_npdata_summon_delay_unlock_to_space  db 074h, 028h, 080h, 07Eh, 032h, 000h, 075h, 022h, 06Ah, 001h, 08Bh, 0CEh
  o_p_npmask_summon_delay_unlock_to_space  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_summon_delay_unlock_to_space  db 074h, 028h, 080h, 07Eh, 032h, 000h, 070h, 022h, 06Ah, 001h, 08Bh, 0CEh
  r_p_npmask_summon_delay_unlock_to_space  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_summon_delay_unlock_to_space  dd   12

  ; 채널 이동 가능하게 하기 (대화,전투일때)
  o_p_npdata_able_channel_move  db 089h, 05Dh, 0FCh, 0FFh, 050h, 004h, 048h, 00Fh, 084h, 0FFh, 0FFh, 0FFh, 0FFh, 048h, 00Fh, 084h, 0FFh, 0FFh, 0FFh, 0FFh, 048h, 074h, 0FFh, 048h, 00Fh, 085h
  o_p_npmask_able_channel_move  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    1,    1,    1,    1,    0,    0,    1,    0,    0,    0
  r_p_npdata_able_channel_move  db 089h, 05Dh, 0FCh, 0FFh, 050h, 004h, 048h, 00Fh, 084h, 0FFh, 0FFh, 0FFh, 0FFh, 048h, 00Fh, 084h, 0D1h, 0FFh, 0FFh, 0FFh, 048h, 074h, 0F7h, 048h, 00Fh, 085h
  r_p_npmask_able_channel_move  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_able_channel_move  dd   26

  ; 로그아웃 가능하게 하기 (대화,전투일때)
  o_p_npdata_able_logout  db 089h, 05Dh, 0FCh, 0FFh, 050h, 004h, 048h, 00Fh, 084h, 0FFh, 0FFh, 0FFh, 0FFh, 048h, 00Fh, 084h, 0FFh, 0FFh, 0FFh, 0FFh, 048h, 00Fh, 085h, 0FFh, 0FFh, 0FFh, 0FFh, 038h, 05Dh, 008h, 074h, 0FFh
  o_p_npmask_able_logout  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    1
  r_p_npdata_able_logout  db 089h, 05Dh, 0FCh, 0FFh, 050h, 004h, 048h, 00Fh, 084h, 0FFh, 0FFh, 0FFh, 0FFh, 048h, 00Fh, 084h, 0D1h, 0FFh, 0FFh, 0FFh, 048h, 00Fh, 085h, 0FFh, 0FFh, 0FFh, 0FFh, 03Bh, 0C0h, 090h, 0EBh, 0EEh
  r_p_npmask_able_logout  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0
  r_p_npcout_able_logout  dd   32

  ; 언제나 장비 교체
  o_p_npdata_always_equip_change  db 084h, 0C0h, 00Fh, 084h, 0D5h, 000h, 000h, 000h, 08Dh, 04Dh, 0DCh, 0FFh, 015h
  o_p_npmask_always_equip_change  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_always_equip_change  db 084h, 0C0h, 00Fh, 080h, 0D5h, 000h, 000h, 000h, 08Dh, 04Dh, 0DCh, 0FFh, 015h
  r_p_npmask_always_equip_change  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_always_equip_change  dd   13

  ; 정령 무기 미착용 대화
  o_p_npdata_ego_talk_noequip  db 084h, 0C0h, 00Fh, 085h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0CEh, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 00Fh, 085h, 0FFh, 0FFh, 0FFh, 0FFh, 068h, 0FFh, 0FFh, 0FFh, 0FFh, 08Dh, 04Dh
  o_p_npmask_ego_talk_noequip  db    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1,    0,    1,    1,    1,    1,    0,    0
  r_p_npdata_ego_talk_noequip  db 084h, 0C0h, 00Fh, 085h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0CEh, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 00Fh, 081h, 0FFh, 0FFh, 0FFh, 0FFh, 068h, 0FFh, 0FFh, 0FFh, 0FFh, 08Dh, 04Dh
  r_p_npmask_ego_talk_noequip  db    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1,    0,    1,    1,    1,    1,    0,    0
  r_p_npcout_ego_talk_noequip  dd   30

  ; NPC 대화 거리문제 수정 
  o_p_npdata_npc_talk_distance_mod  db 0DFh, 0E0h, 0F6h, 0C4h, 001h, 075h, 066h
  o_p_npmask_npc_talk_distance_mod  db    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_npc_talk_distance_mod  db 0DFh, 0E0h, 0F6h, 0C4h, 001h, 070h, 066h
  r_p_npmask_npc_talk_distance_mod  db    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_npc_talk_distance_mod  dd    7

  ; 스케치 시야 땡김 방지
  o_p_npdata_no_vision_maxfar  db 0FFh, 090h, 000h, 001h, 000h, 000h, 08Bh, 037h, 053h, 08Bh, 0CFh, 081h, 0C6h, 01Ch, 001h, 000h, 000h, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 051h, 08Bh, 0CFh, 0D9h, 01Ch, 024h, 0FFh, 016h
  o_p_npmask_no_vision_maxfar  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_no_vision_maxfar  db 0FFh, 090h, 000h, 001h, 000h, 000h, 08Bh, 037h, 090h, 08Bh, 0CFh, 081h, 0C6h, 01Ch, 001h, 000h, 000h, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 090h, 08Bh, 0CFh, 0D9h, 01Ch, 024h, 090h, 090h
  r_p_npmask_no_vision_maxfar  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_no_vision_maxfar  dd   31

  ; 액션 제스쳐 확장 1
  o_p_npdata_all_social_motion1	db 08Bh, 07Dh, 0E0h, 08Dh, 045h, 0E0h, 03Bh, 0F8h, 00Fh, 095h, 0C0h, 084h, 0C0h, 074h, 067h, 08Bh, 035h, 0FFh, 0FFh, 0FFh, 0FFh, 051h, 08Dh, 05Fh, 008h, 08Bh, 0CCh, 089h, 065h, 0ECh
  o_p_npmask_all_social_motion1	db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_all_social_motion1	db 08Bh, 07Dh, 0E0h, 08Dh, 045h, 0E0h, 03Bh, 0F8h, 00Fh, 095h, 0C0h, 084h, 0C0h, 070h, 067h, 08Bh, 035h, 0FFh, 0FFh, 0FFh, 0FFh, 051h, 08Dh, 05Fh, 008h, 08Bh, 0CCh, 089h, 065h, 0ECh
  r_p_npmask_all_social_motion1	db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_all_social_motion1 dd   30
      
  ; 액션 제스쳐 확장 2
  o_p_npdata_all_social_motion2	db 050h, 051h, 0C6h, 045h, 0FCh, 000h, 08Bh, 00Dh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 074h, 019h, 06Ah, 001h, 051h, 08Bh, 0CCh
  o_p_npmask_all_social_motion2	db    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_all_social_motion2	db 050h, 051h, 0C6h, 045h, 0FCh, 000h, 08Bh, 00Dh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 070h, 019h, 06Ah, 001h, 051h, 08Bh, 0CCh
  r_p_npmask_all_social_motion2	db    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_all_social_motion2 dd   27

  ; 스크린샷 워터마크 제거
  o_p_npdata_ss_watermark_remove	db 064h, 000h, 061h, 000h, 074h, 000h, 061h, 000h, 02Fh, 000h, 067h, 000h, 066h, 000h, 078h, 000h, 02Fh, 000h, 069h, 000h, 06Dh, 000h, 061h, 000h, 067h, 000h, 065h, 000h, 02Fh, 000h, 063h, 000h, 06Fh, 000h, 070h, 000h, 079h, 000h, 072h, 000h, 069h, 000h, 067h, 000h, 068h, 000h, 074h, 000h
  o_p_npmask_ss_watermark_remove	db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_ss_watermark_remove	db 064h, 000h, 061h, 000h, 074h, 000h, 061h, 000h, 02Fh, 000h, 067h, 000h, 066h, 000h, 078h, 000h, 02Fh, 000h, 069h, 000h, 06Dh, 000h, 061h, 000h, 067h, 000h, 065h, 000h, 02Fh, 000h, 063h, 000h, 06Fh, 000h, 070h, 000h, 079h, 000h, 072h, 000h, 069h, 000h, 067h, 000h, 000h, 000h, 000h, 000h
  r_p_npmask_ss_watermark_remove	db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_ss_watermark_remove  dd   64

; #######################################################################################################################################################################################################################################
;
;  //  내  구  도  확  장  S t u f f  //
;
  ; 내구도 확장 플레이오네 패치
  o_p_npdata_dura_extend  db 050h, 08Bh, 0CFh, 0FFh, 0D3h, 08Bh, 0CEh, 08Bh, 035h, 0FFh, 0FFh, 0FFh, 0FFh, 050h, 0FFh, 0D6h, 08Bh, 0C8h, 0FFh, 0D6h, 08Bh, 0C8h
  o_p_npmask_dura_extend  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_dura_extend  db 052h, 08Bh, 0CFh, 0FFh, 0D3h, 08Bh, 0CEh, 08Bh, 035h, 0FFh, 0FFh, 0FFh, 0FFh, 052h, 0FFh, 0D6h, 08Bh, 0C8h, 0FFh, 0D6h, 08Bh, 0C8h
  r_p_npmask_dura_extend  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_dura_extend  dd   22

  ; 내구도 확장 스탠다드 패치
  o_s_npdata_dura_extend  db 08Bh, 041h, 0FFh, 005h, 0E7h, 003h, 000h, 000h, 033h, 0D2h, 0B9h, 0E8h, 003h, 000h, 000h, 0F7h, 0F1h, 0C3h, 08Bh, 041h, 0FFh, 005h, 0E7h, 003h, 000h, 000h, 033h, 0D2h, 0B9h, 0E8h, 003h, 000h, 000h, 0F7h, 0F1h, 0C3h
  o_s_npmask_dura_extend  db    0,    0,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_s_npdata_dura_extend  db 08Bh, 041h, 0FFh, 0EBh, 010h, 0B9h, 0E8h, 003h, 000h, 000h, 0F7h, 0F1h, 08Bh, 0D3h, 05Bh, 090h, 090h, 0C3h, 08Bh, 041h, 0FFh, 053h, 08Bh, 0D8h, 005h, 0E7h, 003h, 000h, 000h, 033h, 0D2h, 0EBh, 0E4h, 090h, 090h, 0C3h
  r_s_npmask_dura_extend  db    0,    0,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_s_npcout_dura_extend  dd   36

  ; 내구도 확장 STRING PUSH 위치 변경
  o_p_npdata_dura_ext_push  db 050h, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 08Bh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 00Fh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 068h, 0FFh, 0FFh, 0FFh, 0FFh, 08Dh, 04Dh, 0ECh
  o_p_npmask_dura_ext_push  db    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    1,    1,    1,    1,    1,    0,    1,    1,    1,    1,    1,    0,    1,    1,    1,    1,    0,    0,    0
  r_p_npdata_dura_ext_push  db 050h, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 08Bh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 00Fh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 068h, 04Dh, 004h, 080h, 063h, 08Dh, 04Dh, 0ECh
  r_p_npmask_dura_ext_push  db    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    1,    1,    1,    1,    1,    0,    1,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_dura_ext_push  dd   29
  
  ; 내구도 확장+기존내구 플레이오네 패치 (우회 CALL)
  o_p_npdata_dura_ext_call  db 08Bh, 0F0h, 08Dh, 045h, 0F0h, 050h, 08Bh, 0CFh, 0C6h, 045h, 0FCh, 002h, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 035h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0C8h, 0FFh, 015h
  o_p_npmask_dura_ext_call  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    0,    0,    0,    0
  r_p_npdata_dura_ext_call  db 08Bh, 0F0h, 08Dh, 045h, 0F0h, 050h, 08Bh, 0CFh, 0C6h, 045h, 0FCh, 002h, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 0B9h, 038h, 004h, 080h, 063h, 0FFh, 0D1h, 08Bh, 035h, 0FFh, 0FFh, 0FFh, 0FFh, 0BAh, 0BEh, 004h, 080h, 063h, 0FFh, 0D2h, 08Bh, 0C8h, 0FFh, 015h
  r_p_npmask_dura_ext_call  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_dura_ext_call  dd   42

  ; Durability 1234/5678 (a/b)
  o_p_npdata_dura_str    db 044h, 000h, 075h, 000h, 072h, 000h, 061h, 000h, 062h, 000h, 069h, 000h, 06Ch, 000h, 069h, 000h, 074h, 000h, 079h, 000h, 020h, 000h, 07Bh, 000h, 031h, 000h, 07Dh, 000h, 02Fh, 000h, 07Bh, 000h, 033h, 000h, 07Dh, 000h, 020h, 000h, 028h, 000h, 07Bh, 000h, 030h
                         db 000h, 07Dh, 000h, 02Fh, 000h, 07Bh, 000h, 032h, 000h, 07Dh, 000h, 029h, 000h, 000h
  o_p_npmask_dura_str    db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
                         db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  o_p_npcout_dura_str    dd   57

  ; A Type [내구력 1234/5678 (a/b)]
  r_p_npdata_dura_str_a	 db 0B4h, 0B0h, 06Ch, 0ADh, 025h, 0B8h, 020h, 000h, 07Bh, 000h, 031h, 000h, 07Dh, 000h, 02Fh, 000h, 07Bh, 000h, 033h, 000h, 07Dh, 000h, 020h, 000h, 028h, 000h, 07Bh, 000h, 030h, 000h, 07Dh, 000h, 02Fh, 000h, 07Bh, 000h, 032h, 000h, 07Dh, 000h, 029h, 000h, 000h
                         db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
  r_p_npmask_dura_str_a  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
                         db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0

  ; B Type [내구력 a/b (1234/5678)]
  r_p_npdata_dura_str_b	 db 0B4h, 0B0h, 06Ch, 0ADh, 025h, 0B8h, 020h, 000h, 07Bh, 000h, 030h, 000h, 07Dh, 000h, 02Fh, 000h, 07Bh, 000h, 032h, 000h, 07Dh, 000h, 020h, 000h, 028h, 000h, 07Bh, 000h, 031h, 000h, 07Dh, 000h, 02Fh, 000h, 07Bh, 000h, 033h, 000h, 07Dh, 000h, 029h, 000h, 000h
                         db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
  r_p_npmask_dura_str_b  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
                         db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0

  ; C Type [내구력 1234/5678]
  r_p_npdata_dura_str_c	 db 0B4h, 0B0h, 06Ch, 0ADh, 025h, 0B8h, 020h, 000h, 07Bh, 000h, 031h, 000h, 07Dh, 000h, 02Fh, 000h, 07Bh, 000h, 033h, 000h, 07Dh, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
                         db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
  r_p_npmask_dura_str_c  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
                         db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0

  ; Eng-A Type [Durability 1234/5678 (a/b)]
  ;r_p_npdata_dura_str_eng_a    db 044h, 000h, 075h, 000h, 072h, 000h, 061h, 000h, 062h, 000h, 069h, 000h, 06Ch, 000h, 069h, 000h, 074h, 000h, 079h, 000h, 020h, 000h, 07Bh, 000h, 031h, 000h, 07Dh, 000h, 02Fh, 000h, 07Bh, 000h, 033h, 000h, 07Dh, 000h, 020h, 000h, 028h, 000h, 07Bh, 000h, 030h
  ;                             db 000h, 07Dh, 000h, 02Fh, 000h, 07Bh, 000h, 032h, 000h, 07Dh, 000h, 029h, 000h, 000h
  ;r_p_npmask_dura_str_eng_a    db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  ;                             db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0

  ; Eng-B Type [Durability a/b (1234/5678)]
  r_p_npdata_dura_str_eng_b     db 044h, 000h, 075h, 000h, 072h, 000h, 061h, 000h, 062h, 000h, 069h, 000h, 06Ch, 000h, 069h, 000h, 074h, 000h, 079h, 000h, 020h, 000h, 07Bh, 000h, 030h, 000h, 07Dh, 000h, 02Fh, 000h, 07Bh, 000h, 032h, 000h, 07Dh, 000h, 020h, 000h, 028h, 000h, 07Bh, 000h, 031h
                                db 000h, 07Dh, 000h, 02Fh, 000h, 07Bh, 000h, 033h, 000h, 07Dh, 000h, 029h, 000h, 000h
  r_p_npmask_dura_str_eng_b     db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
                                db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0

  ; Eng-C Type [durability 1234/5678]
  r_p_npdata_dura_str_eng_c     db 044h, 000h, 075h, 000h, 072h, 000h, 061h, 000h, 062h, 000h, 069h, 000h, 06Ch, 000h, 069h, 000h, 074h, 000h, 079h, 000h, 020h, 000h, 07Bh, 000h, 030h, 000h, 07Dh, 000h, 02Fh, 000h, 07Bh, 000h, 032h, 000h, 07Dh, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
                                db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
  r_p_npmask_dura_str_eng_c     db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
                                db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0

; #######################################################################################################################################################################################################################################
;
;  //  게  시  판    바  로  열  기  S t u f f  //
;
  ; 게시판 바로열기1
  o_p_npdata_bbsbaro1  db 084h, 0C0h, 00Fh, 084h, 0FFh, 0FFh, 0FFh, 0FFh, 038h, 05Dh, 010h, 08Bh, 035h, 0FFh, 0FFh, 0FFh, 0FFh, 00Fh, 084h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 04Dh, 0ECh, 068h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 074h, 0FFh, 08Bh, 04Dh, 0FFh
  o_p_npmask_bbsbaro1  db    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    0,    1,    0,    0,    1
  r_p_npdata_bbsbaro1  db 0EBh, 017h, 00Fh, 084h, 0FFh, 0FFh, 0FFh, 0FFh, 038h, 05Dh, 010h, 08Bh, 035h, 0FFh, 0FFh, 0FFh, 0FFh, 00Fh, 084h, 0FFh, 0FFh, 0FFh, 0FFh, 0EBh, 028h, 050h, 0B8h, 0E0h, 002h, 080h, 063h, 0FFh, 035h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0D0h, 090h, 0E3h, 0D8h, 077h, 0DCh
  r_p_npmask_bbsbaro1  db    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_bbsbaro1  dd   44

  ; 게시판 바로열기2 (계속열림방지)
  o_p_npdata_bbsbaro2  db 068h, 08Bh, 090h, 000h, 000h, 08Bh, 0CEh, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 08Dh, 04Dh, 008h, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 03Ch, 064h, 00Fh, 085h, 0FFh, 0FFh, 0FFh, 0FFh, 08Dh, 04Dh, 008h, 0FFh, 015h
  o_p_npmask_bbsbaro2  db    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0
  r_p_npdata_bbsbaro2  db 068h, 08Bh, 090h, 000h, 000h, 08Bh, 0CEh, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 08Dh, 04Dh, 008h, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 03Ch, 064h, 00Fh, 081h, 0FFh, 0FFh, 0FFh, 0FFh, 08Dh, 04Dh, 008h, 0FFh, 015h
  r_p_npmask_bbsbaro2  db    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0
  r_p_npcout_bbsbaro2  dd   34

  ; 게시판 바로열기3 (미션 멀리서 수주받기)
  o_p_npdata_bbsbaro3  db 03Bh, 086h, 014h, 001h, 000h, 000h, 00Fh, 085h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 086h, 0FFh, 0FFh, 0FFh, 0FFh, 0DBh, 086h, 0FFh, 0FFh, 0FFh, 0FFh, 085h, 0C0h
  o_p_npmask_bbsbaro3  db    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0
  r_p_npdata_bbsbaro3  db 03Bh, 086h, 014h, 001h, 000h, 000h, 00Fh, 080h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 086h, 0FFh, 0FFh, 0FFh, 0FFh, 0DBh, 086h, 0FFh, 0FFh, 0FFh, 0FFh, 085h, 0C0h
  r_p_npmask_bbsbaro3  db    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0
  r_p_npcout_bbsbaro3  dd   26

  ; 게시판 바로열기4 (미션 멀리서 수주받기)
  o_p_npdata_bbsbaro4  db 0DFh, 0E0h, 0F6h, 0C4h, 041h, 00Fh, 084h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 086h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 03Dh
  o_p_npmask_bbsbaro4  db    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0
  r_p_npdata_bbsbaro4  db 0DFh, 0E0h, 0F6h, 0C4h, 041h, 00Fh, 080h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 086h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 03Dh
  r_p_npmask_bbsbaro4  db    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0
  r_p_npcout_bbsbaro4  dd   19

; #######################################################################################################################################################################################################################################
;
;  //  노  기  노  기    카  레  //
;
  ; NPC 클릭하고 움직이기
  o_p_npdata_kare1  db 083h, 078h, 04Ch, 000h, 074h, 013h
  o_p_npmask_kare1  db    0,    0,    0,    0,    0,    0
  r_p_npdata_kare1  db 083h, 078h, 04Ch, 000h, 0EBh, 013h
  r_p_npmask_kare1  db    0,    0,    0,    0,    0,    0
  r_p_npcout_kare1  dd    6

  ; NPC 클릭시 창 닫히지 않게 하기
  o_p_npdata_kare2  db 00Fh, 084h, 0B2h, 000h, 000h, 000h, 053h, 06Ah, 003h
  o_p_npmask_kare2  db    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_kare2  db 0E9h, 0B3h, 000h, 000h, 000h, 090h, 053h, 06Ah, 003h
  r_p_npmask_kare2  db    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_kare2  dd    9

; #######################################################################################################################################################################################################################################
;
;  //  던  전    미  니  맵    보  기  //
;
  ; 던전지도1
  o_p_npdata_dungeon_minimap1  db 00Fh, 084h, 0BCh, 000h, 000h, 000h, 08Dh, 07Bh, 024h
  o_p_npmask_dungeon_minimap1  db    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_dungeon_minimap1  db 00Fh, 080h, 0BCh, 000h, 000h, 000h, 08Dh, 07Bh, 024h
  r_p_npmask_dungeon_minimap1  db    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_dungeon_minimap1  dd    9
  
  ; 던전지도2
  o_p_npdata_dungeon_minimap2  db 075h, 06Ch, 00Fh, 0B6h, 006h
  o_p_npmask_dungeon_minimap2  db    0,    0,    0,    0,    0
  r_p_npdata_dungeon_minimap2  db 070h, 06Ch, 00Fh, 0B6h, 006h
  r_p_npmask_dungeon_minimap2  db    0,    0,    0,    0,    0
  r_p_npcout_dungeon_minimap2  dd    5
  
  ; 던전지도3
  o_p_npdata_dungeon_minimap3  db 074h, 004h, 0C6h, 045h, 0D7h, 000h
  o_p_npmask_dungeon_minimap3  db    0,    0,    0,    0,    0,    0
  r_p_npdata_dungeon_minimap3  db 070h, 004h, 0C6h, 045h, 0D7h, 000h
  r_p_npmask_dungeon_minimap3  db    0,    0,    0,    0,    0,    0
  r_p_npcout_dungeon_minimap3  dd    6

; #######################################################################################################################################################################################################################################
;
;  //  미  믹  &  유  황  골  렘    이  름  표    보  기  //
;
  ; 미믹 이름표 
  o_s_npdata_mimic_naming  db 02Fh, 000h, 06Dh, 000h, 069h, 000h, 06Dh, 000h, 069h, 000h, 063h, 000h, 02Fh
  o_s_npmask_mimic_naming  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_s_npdata_mimic_naming  db 000h, 000h, 06Dh, 000h, 069h, 000h, 06Dh, 000h, 069h, 000h, 063h, 000h, 02Fh
  r_s_npmask_mimic_naming  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_s_npcout_mimic_naming  dd   13
  
  ; 유황골렘 이름표
  o_s_npdata_sf_golem_naming  db 02Fh, 000h, 073h, 000h, 075h, 000h, 06Ch, 000h, 066h, 000h, 075h, 000h, 072h, 000h, 067h, 000h, 06Fh, 000h, 06Ch, 000h, 065h, 000h, 06Dh, 000h, 02Fh
  o_s_npmask_sf_golem_naming  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_s_npdata_sf_golem_naming  db 000h, 000h, 073h, 000h, 075h, 000h, 06Ch, 000h, 066h, 000h, 075h, 000h, 072h, 000h, 067h, 000h, 06Fh, 000h, 06Ch, 000h, 065h, 000h, 06Dh, 000h, 02Fh
  r_s_npmask_sf_golem_naming  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_s_npcout_sf_golem_naming  dd   25

; #######################################################################################################################################################################################################################################
;
;  //  노  기  노  기    리  르  -  아  이  템    드  롭  여  부    확  인  //
;
  ; 아이템 드롭 묻기
  o_p_npdata_lire  db 072h, 004h, 0C6h, 045h, 0F2h, 001h, 08Bh, 07Dh, 0E8h, 038h, 05Dh, 0F3h, 00Fh, 084h
  o_p_npmask_lire  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_lire  db 072h, 004h, 0C6h, 045h, 0F2h, 001h, 08Bh, 07Dh, 0E8h, 038h, 05Dh, 0F3h, 00Fh, 080h
  r_p_npmask_lire  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_lire  dd   14

; #######################################################################################################################################################################################################################################
;
;  //  노  기  노  기    모  카  간  소  화  //
;
  ; 간소화 프레임 무시
  o_p_npdata_ignore_frame	db 08Bh, 008h, 08Bh, 001h, 0FFh, 090h, 0FFh, 001h, 000h, 000h, 003h
  o_p_npmask_ignore_frame db    0,    0,    0,    0,    0,    0,    1,    0,    0,    0,    0
  r_p_npdata_ignore_frame db 08Bh, 008h, 08Bh, 001h, 0B8h, 000h, 000h, 000h, 000h, 090h, 003h 
  r_p_npmask_ignore_frame db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_ignore_frame dd   11
  
  ; 모카 간소화 1
  o_p_npdata_moca_pt db 088h, 046h, 011h, 08Bh, 045h, 010h, 089h, 046h, 014h, 08Ah, 045h, 014h, 089h, 0FFh, 00Ch, 08Bh, 0FFh, 018h, 088h, 046h, 018h
  o_p_npmask_moca_pt db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    0,    0,    1,    0,    0,    0,    0
  r_p_npdata_moca_pt db 0EBh, 00Ah, 050h, 0B8h, 0DBh, 004h, 080h, 063h, 0FFh, 0D0h, 0EBh, 008h, 089h, 0FFh, 00Ch, 08Bh, 0FFh, 018h, 0EBh, 0EEh, 058h
  r_p_npmask_moca_pt db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    0,    0,    1,    0,    0,    0,    0
  r_p_npcout_moca_pt dd   21
  
  ; 모카 간소화 2
  o_p_npdata_moca_pt2 db 0E9h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 07Dh, 00Ch, 085h, 0FFh, 075h, 01Fh, 08Bh, 0CBh, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0F8h, 085h, 0FFh, 075h, 012h, 083h, 04Dh, 0FCh, 0FFh
  o_p_npmask_moca_pt2 db    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_moca_pt2 db 0E9h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 07Dh, 00Ch, 085h, 0FFh, 075h, 01Fh, 08Bh, 0CBh, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0F8h, 085h, 0FFh, 0EBh, 012h, 083h, 04Dh, 0FCh, 0FFh
  r_p_npmask_moca_pt2 db    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_moca_pt2 dd   29

  ; 모카 간소화 3
  o_p_npdata_moca_pt3 db 068h, 0FEh, 032h, 000h, 000h, 06Ah, 0FEh, 0E8h
  o_p_npmask_moca_pt3 db    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_moca_pt3 db 068h, 078h, 056h, 034h, 012h, 06Ah, 0FEh, 0E8h
  r_p_npmask_moca_pt3 db    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_moca_pt3 dd    8

  ; 모카 간소화 4
  o_p_npdata_moca_pt4 db 08Bh, 0C8h, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0C8h, 085h, 0C9h, 089h, 0FFh, 0FFh, 00Fh, 084h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 075h, 008h, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 083h, 0C4h, 004h, 083h
                      db 0F8h, 0FFh, 089h, 0FFh, 0FFh, 00Fh, 084h, 0FFh, 0FFh, 0FFh, 0FFh, 06Bh, 0C0h, 02Ch, 08Dh, 034h, 0FFh, 0C6h, 046h, 008h, 001h, 0FFh, 015h
  o_p_npmask_moca_pt4 db    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0
                      db    0,    0,    0,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    1,    0,    0,    0,    0,    0,    0
  r_p_npdata_moca_pt4 db 08Bh, 0C8h, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0C8h, 085h, 0C9h, 089h, 0FFh, 0FFh, 0FFh, 015h, 0FFh, 004h, 080h, 063h, 090h, 074h, 00Eh, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 083h, 0C4h, 004h, 083h
                      db 0F8h, 0FFh, 089h, 0FFh, 0FFh, 00Fh, 084h, 0FFh, 0FFh, 0FFh, 0FFh, 06Bh, 0C0h, 02Ch, 08Dh, 034h, 0FFh, 0FFh, 0D2h, 074h, 032h, 0FFh, 015h
  r_p_npmask_moca_pt4 db    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0
                      db    0,    0,    0,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    1,    0,    0,    0,    0,    0,    0
  r_p_npcout_moca_pt4 dd   55

	;======== 펫간소화 ========
  o_p_npdata_mocapet db 08Bh, 0F1h, 00Fh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0CDh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh
                     db 084h, 0C0h, 00Fh, 085h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0CDh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh
                     db 084h, 0C0h, 00Fh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0CDh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh
                     db 084h, 0C0h, 00Fh, 0FFh, 0FFh
  o_p_npmask_mocapet db    0,    0,    0,    1,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1
                     db    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1
                     db    0,    0,    0,    1,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1
                     db    0,    0,    0,    1,    1
  r_p_npdata_mocapet db 08Bh, 0F1h, 00Fh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0CDh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh
                     db 084h, 0C0h, 00Fh, 080h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0CDh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh
                     db 084h, 0C0h, 00Fh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0CDh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh
                     db 084h, 0C0h, 00Fh, 0FFh, 0FFh
  r_p_npmask_mocapet db    0,    0,    0,    1,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1
                     db    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1
                     db    0,    0,    0,    1,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1
                     db    0,    0,    0,    1,    1
  r_p_npcout_mocapet dd   53

	;======== 변신간소화 ========
  o_p_npdata_moca_vtchar db 08Bh, 0F1h, 00Fh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0CDh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh
                         db 084h, 0C0h, 00Fh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0CDh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh
                         db 084h, 0C0h, 00Fh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0CDh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh
                         db 084h, 0C0h, 00Fh, 085h, 0FFh
  o_p_npmask_moca_vtchar db    0,    0,    0,    1,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1
                         db    0,    0,    0,    1,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1
                         db    0,    0,    0,    1,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1
                         db    0,    0,    0,    0,    1
  r_p_npdata_moca_vtchar db 08Bh, 0F1h, 00Fh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0CDh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh
                         db 084h, 0C0h, 00Fh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0CDh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh
                         db 084h, 0C0h, 00Fh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0CDh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh
                         db 084h, 0C0h, 00Fh, 080h, 0FFh
  r_p_npmask_moca_vtchar db    0,    0,    0,    1,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1
                         db    0,    0,    0,    1,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1
                         db    0,    0,    0,    1,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1
                         db    0,    0,    0,    0,    1
  r_p_npcout_moca_vtchar dd   53

	;======== NPC 간소화 ========
  o_p_npdata_moca_npcchar db 08Bh, 0F1h, 00Fh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0CDh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh
                          db 084h, 0C0h, 00Fh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0CDh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh
                          db 084h, 0C0h, 00Fh, 085h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0CDh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh
                          db 084h, 0C0h, 00Fh, 0FFh, 0FFh
  o_p_npmask_moca_npcchar db    0,    0,    0,    1,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1
                          db    0,    0,    0,    1,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1
                          db    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1
                          db    0,    0,    0,    1,    1
  r_p_npdata_moca_npcchar db 08Bh, 0F1h, 00Fh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0CDh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh
                          db 084h, 0C0h, 00Fh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0CDh, 090h, 0BAh, 0FFh, 0FFh, 0FFh, 0FFh
                          db 0B8h, 08Ch, 004h, 080h, 063h, 0FFh, 0D0h, 075h, 0D9h, 090h, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh
                          db 084h, 0C0h, 00Fh, 0FFh, 0FFh
  r_p_npmask_moca_npcchar db    0,    0,    0,    1,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1
                          db    0,    0,    0,    1,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1
                          db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1
                          db    0,    0,    0,    1,    1
  r_p_npcout_moca_npcchar dd   53

  ; 모카 NPC간소화 영역패치 (NPC와 MOB 모두 간소화)
  o_p_npdata_moca_npcchar3 db 08Bh, 0CDh, 074h, 00Dh, 0FFh, 052h, 004h, 08Bh, 0CDh, 074h, 004h, 0B0h, 0FFh, 0EBh, 002h, 0B0h, 0FFh
  o_p_npmask_moca_npcchar3 db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    0,    0,    0,    1
  r_p_npdata_moca_npcchar3 db 08Bh, 0CDh, 074h, 00Dh, 0FFh, 052h, 004h, 08Bh, 0CDh, 074h, 004h, 0B0h, 000h, 0EBh, 002h, 0B0h, 000h
  r_p_npmask_moca_npcchar3 db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_moca_npcchar3 dd   17

  ; 모카 NPC간소화 영역패치 (NPC만 간소화)
  o_p_npdata_moca_npcchar4 db 08Bh, 0CDh, 074h, 00Dh, 0FFh, 052h, 004h, 08Bh, 0CDh, 074h, 004h, 0B0h, 0FFh, 0EBh, 002h, 0B0h, 0FFh
  o_p_npmask_moca_npcchar4 db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    0,    0,    0,    1
  r_p_npdata_moca_npcchar4 db 08Bh, 0CDh, 074h, 00Dh, 0FFh, 052h, 004h, 08Bh, 0CDh, 074h, 004h, 0B0h, 000h, 0EBh, 002h, 0B0h, 001h
  r_p_npmask_moca_npcchar4 db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_moca_npcchar4 dd   17

; #########################################################################		

  ; login_dep
  o_p_npdata_login_dep  db 068h, 0FFh, 0FFh, 0FFh, 0FFh, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0C8h, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 089h, 086h, 0FFh, 0FFh, 0FFh, 0FFh, 089h, 045h, 0F0h, 03Bh, 0C7h, 089h, 07Dh, 0FCh, 074h, 007h, 08Bh, 0C8h
  o_p_npmask_login_dep  db    0,    1,    1,    1,    1,    0,    1,    1,    1,    1,    0,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_login_dep  db 068h, 0FFh, 0FFh, 0FFh, 0FFh, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0C8h, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 089h, 086h, 0FFh, 0FFh, 0FFh, 0FFh, 0BAh, 0B1h, 004h, 080h, 063h, 0FFh, 0D2h, 090h, 074h, 007h, 08Bh, 0C8h
  r_p_npmask_login_dep  db    0,    1,    1,    1,    1,    0,    1,    1,    1,    1,    0,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_login_dep  dd   35

; #########################################################################
;
;  노기노기 로나 - 파티창 숨김시 아이템 툴팁에 상점가 표시
;
; #########################################################################

  ; 노기노기 로나 - 상점가 표시 1
  o_p_npdata_rona1  db 08Bh, 087h, 0ACh, 000h, 000h, 000h, 083h, 0F8h, 001h, 00Fh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0B0h, 0BCh, 000h, 000h, 000h
  o_p_npmask_rona1  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    1,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0
  r_p_npdata_rona1  db 090h, 090h, 0BAh, 0B7h, 003h, 080h, 063h, 0EBh, 006h, 00Fh, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0D2h, 075h, 0F1h, 052h, 090h
  r_p_npmask_rona1  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    1,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0
  r_p_npcout_rona1  dd   26

  ; 노기노기 로나 - 상점가 표시 2
  o_p_npdata_rona2  db 083h, 0F8h, 002h, 00Fh, 085h, 0FFh, 0FFh, 0FFh, 0FFh, 068h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0CEh, 0FFh, 015h
  o_p_npmask_rona2  db    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    1,    1,    1,    1,    0,    0,    0,    0
  r_p_npdata_rona2  db 083h, 0F8h, 002h, 00Fh, 085h, 0FFh, 0FFh, 0FFh, 0FFh, 052h, 090h, 090h, 090h, 090h, 08Bh, 0CEh, 0FFh, 015h
  r_p_npmask_rona2  db    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_rona2  dd   18

; #########################################################################
;
;  노기노기 괴수탐지
;
; #########################################################################
  o_p_npdata_gt1	db 0C7h, 046h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0C7h, 046h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0CFh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 08Bh, 0CFh, 074h, 01Ah
  o_p_npmask_gt1	db   0,    0,    1,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0
  r_p_npdata_gt1	db 0C7h, 046h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 0C7h, 046h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0CFh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 08Bh, 0CFh, 070h, 01Ah
  r_p_npmask_gt1	db   0,    0,    1,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0
  r_p_npcout_gt1  dd  28

  o_p_npdata_gt2	db 08Bh, 0F1h, 083h, 065h, 0E8h, 000h, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 00Fh, 084h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0CEh
  o_p_npmask_gt2	db   0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0
  r_p_npdata_gt2	db 08Bh, 0F1h, 083h, 065h, 0E8h, 000h, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0DBh, 00Fh, 085h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0CEh
  r_p_npmask_gt2	db   0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0
  r_p_npcout_gt2  dd  22


  ; 자기 자신에게 교환 걸기
  o_p_npdata_selftrade  db 0FFh, 0D7h, 03Bh, 045h, 008h, 00Fh, 085h
  o_p_npmask_selftrade  db    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_selftrade  db 0FFh, 0D7h, 03Bh, 045h, 008h, 00Fh, 081h
  r_p_npmask_selftrade  db    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_selftrade  dd    7

  ; 캐릭터 우클릭 메뉴 확장
  o_p_npdata_right_menu_extend  db 084h, 0C0h, 00Fh, 085h, 0D4h, 007h, 000h, 000h, 08Bh, 0DFh
  o_p_npmask_right_menu_extend  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_right_menu_extend  db 084h, 0C0h, 00Fh, 080h, 0D4h, 007h, 000h, 000h, 08Bh, 0DFh
  r_p_npmask_right_menu_extend  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_right_menu_extend  dd   10

  ; 스킬창에 아무 아이템이나 올리기
  o_p_npdata_upitem		db 05Bh, 0C3h, 08Bh, 04Ch, 024h, 004h, 085h, 0C9h, 074h, 013h, 068h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 074h, 004h, 0B0h, 001h, 0EBh, 002h, 032h, 0C0h, 0C2h, 004h, 000h, 056h
  o_p_npmask_upitem		db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_upitem		db 05Bh, 0C3h, 08Bh, 04Ch, 024h, 004h, 085h, 0C9h, 074h, 013h, 068h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 070h, 004h, 0B0h, 001h, 0EBh, 002h, 032h, 0C0h, 0C2h, 004h, 000h, 056h
  r_p_npmask_upitem		db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_upitem		dd   35

  ; 일체화 스킬 1
  o_p_npdata_p_temp1  db 052h, 08Dh, 04Dh, 0CCh, 050h, 074h, 05Ah
  o_p_npmask_p_temp1  db    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_p_temp1  db 052h, 08Dh, 04Dh, 0CCh, 050h, 0EBh, 05Ah
  r_p_npmask_p_temp1  db    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_p_temp1  dd    7

  ; 일체화 스킬 2
  o_p_npdata_p_temp2  db 080h, 07Dh, 0F3h, 000h, 074h, 00Ch, 08Bh, 04Dh, 0ECh, 06Ah, 000h
  o_p_npmask_p_temp2  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npdata_p_temp2  db 080h, 07Dh, 0F3h, 000h, 0EBh, 00Ch, 08Bh, 04Dh, 0ECh, 06Ah, 000h
  r_p_npmask_p_temp2  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_p_npcout_p_temp2  dd   11

  ; 라볼 방전 방지
  o_s_npdata_lightning_discharge  db 053h, 000h, 074h, 000h, 061h, 000h, 063h, 000h, 06Bh, 000h, 04Ch, 000h, 069h, 000h, 06Dh, 000h, 069h, 000h, 074h, 000h, 054h, 000h, 069h, 000h, 06Dh, 000h, 065h
  o_s_npmask_lightning_discharge  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_s_npdata_lightning_discharge  db 000h, 000h, 074h, 000h, 061h, 000h, 063h, 000h, 06Bh, 000h, 04Ch, 000h, 069h, 000h, 06Dh, 000h, 069h, 000h, 074h, 000h, 054h, 000h, 069h, 000h, 06Dh, 000h, 065h
  r_s_npmask_lightning_discharge  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_s_npcout_lightning_discharge  dd   27

  ; 마비노기 멀리보기
  o_r_npdata_farview  db 080h, 0BBh, 044h, 000h
  o_r_npmask_farview  db    0,    0,    0,    0
  r_r_npdata_farview  db 040h, 09Ch, 045h, 000h
  r_r_npmask_farview  db    0,    0,    0,    0
  r_r_npcout_farview  dd    4

  ; 마비노기 가까이보기
  o_r_npdata_closeview  db 000h, 000h, 0C8h, 043h, 000h
  o_r_npmask_closeview  db    0,    0,    0,    0,    0
  r_r_npdata_closeview  db 000h, 000h, 048h, 043h, 000h
  r_r_npmask_closeview  db    0,    0,    0,    0,    0
  r_r_npcout_closeview  dd    5

  ; 멀리 땡겨지지 않게
  o_r_npdata_no_maxfar  db 0D9h, 098h, 0D0h, 000h, 000h, 000h, 08Bh, 046h, 064h, 0D9h, 005h, 0FFh, 0FFh, 0FFh, 0FFh, 051h, 0D9h, 098h
  o_r_npmask_no_maxfar  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    1,    1,    1
  r_r_npdata_no_maxfar  db 052h, 0BAh, 020h, 007h, 080h, 063h, 0FFh, 0D2h, 0EBh, 006h, 090h, 0FFh, 0D0h, 090h, 090h, 051h, 0D9h, 098h
  r_r_npmask_no_maxfar  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  r_r_npcout_no_maxfar  dd   18

  ; data 폴더 우선권 (ESL.?SetLookUpOrder@CFileSystem@esl@@QAEXW4EFileLookUpOrder@esl_constant@2@@Z+0AF)
  o_e_npdata_force_data_folder  db 08Bh, 045h, 0FFh, 08Bh, 040h, 0FFh, 08Bh, 040h, 0FFh, 083h, 0E8h, 000h, 00Fh, 084h, 0FFh, 0FFh, 0FFh, 0FFh, 048h, 00Fh, 084h, 0FFh, 0FFh, 0FFh, 0FFh, 048h, 074h, 0FFh, 048h, 00Fh, 085h, 0FFh, 0FFh, 0FFh, 0FFh
  o_e_npmask_force_data_folder  db    0,    0,    1,    0,    0,    1,    0,    0,    1,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    1,    1,    1,    1,    0,    0,    1,    0,    0,    0,    1,    1,    1,    1
  r_e_npdata_force_data_folder  db 08Bh, 045h, 0FFh, 08Bh, 040h, 0FFh, 08Bh, 040h, 0FFh, 083h, 0E8h, 001h, 00Fh, 084h, 0FFh, 0FFh, 0FFh, 0FFh, 048h, 00Fh, 084h, 0FFh, 0FFh, 0FFh, 0FFh, 048h, 074h, 0FFh, 048h, 00Fh, 085h, 0FFh, 0FFh, 0FFh, 0FFh
  r_e_npmask_force_data_folder  db    0,    0,    1,    0,    0,    1,    0,    0,    1,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    1,    1,    1,    1,    0,    0,    1,    0,    0,    0,    1,    1,    1,    1
  r_e_npcout_force_data_folder  dd   35

; #########################################################################
;
;  노기노기 컬러링
;
; #########################################################################

  ; 노기노기 컬러링
  o_p_npdata_altcolor  db 0C7h, 046h, 058h, 000h, 0CCh, 099h, 0FFh, 0C7h, 046h, 05Ch, 000h, 0CCh, 099h, 030h, 0EBh, 00Eh
  										 db 0C7h, 046h, 058h, 0FFh, 066h, 033h, 0FFh, 0C7h, 046h, 05Ch, 0FFh, 066h, 033h, 030h, 08Bh, 0CFh
  										 db 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 08Bh, 0CFh, 0FFh, 01Ah, 08Dh, 045h, 008h
  o_p_npmask_altcolor  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  										 db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  										 db    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    1,    0,    0,    0,    0
  r_p_npdata_altcolor  db 0C7h, 046h, 058h, 064h, 082h, 0C8h, 0FFh, 0C7h, 046h, 05Ch, 064h, 082h, 0C8h, 000h, 0EBh, 00Bh
  										 db 0EBh, 00Eh, 0B8h, 050h, 005h, 080h, 063h, 0FFh, 0D0h, 0EBh, 00Dh, 08Bh, 0CFh, 0EBh, 00Dh, 090h
  										 db 08Bh, 01Dh, 0FFh, 0FFh, 0FFh, 0FFh, 0EBh, 0EAh, 08Bh, 0CFh, 0FFh, 01Ah, 08Dh, 045h, 008h
  r_p_npmask_altcolor  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  										 db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  										 db    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    1,    0,    0,    0,    0
  r_p_npcout_altcolor  dd   47



  ; 제로 고도 비행
  o_p_npdata_zerohigh	 db 03Dh, 02Ch, 001h, 000h, 000h, 074h, 019h, 08Bh, 006h, 08Bh, 0CEh, 0FFh, 090h, 0FFh, 0FFh, 0FFh
  										 db 0FFh, 03Dh, 091h, 001h, 000h, 000h, 074h, 008h, 0D9h, 005h, 0FFh, 0FFh, 0FFh, 0FFh, 0EBh, 006h
  										 db 0D9h, 005h, 0FFh, 0FFh, 0FFh, 0FFh, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 0C3h
  o_p_npmask_zerohigh  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1
  										 db    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0
  										 db    0,    0,    1,    1,    1,    1,    0,    1,    1,    1,    1,    0
  r_p_npdata_zerohigh	 db 03Dh, 02Ch, 001h, 000h, 000h, 074h, 019h, 08Bh, 006h, 08Bh, 0CEh, 0FFh, 090h, 0FFh, 0FFh, 0FFh
  										 db 0FFh, 03Dh, 091h, 001h, 000h, 000h, 074h, 008h, 090h, 090h, 090h, 090h, 090h, 090h, 090h, 090h
  										 db 0D9h, 005h, 020h, 000h, 080h, 063h, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 0C3h
  r_p_npmask_zerohigh  db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1
  										 db    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
  										 db    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0
  r_p_npcout_zerohigh  dd   44

	; 은행탭 강제 활성화
	o_p_npdata_bank_tab	db 08Bh, 01Dh, 0FFh, 0FFh, 0FFh, 0FFh, 076h, 0FFh, 0FFh, 075h, 0F0h, 08Bh, 08Eh
	o_p_npmask_bank_tab db    0,    0,    1,    1,    1,    1,    0,    1,    0,    0,    0,    0,    0
	r_p_npdata_bank_tab	db 08Bh, 01Dh, 0FFh, 0FFh, 0FFh, 0FFh, 070h, 0FFh, 0FFh, 075h, 0F0h, 08Bh, 08Eh
	r_p_npmask_bank_tab db    0,    0,    1,    1,    1,    1,    0,    1,    0,    0,    0,    0,    0
	r_p_npcout_bank_tab dd   13
	
	; 은행탭 강제 활성화2
	o_p_npdata_bank_tab2	db 0FFh, 0D3h, 084h, 0C0h, 08Bh, 08Eh, 0FFh, 0FFh, 0FFh, 0FFh, 075h, 004h, 06Ah, 000h, 0EBh, 002h, 06Ah, 001h
	o_p_npmask_bank_tab2	db    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0
	r_p_npdata_bank_tab2	db 0FFh, 0D3h, 084h, 0C0h, 08Bh, 08Eh, 0FFh, 0FFh, 0FFh, 0FFh, 0EBh, 004h, 06Ah, 000h, 0EBh, 002h, 06Ah, 001h
	r_p_npmask_bank_tab2	db    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0
	r_p_npcout_bank_tab2	dd 	 18
	
	; 변신 효과 무시
	o_p_npdata_transform_eff_ignore1 	db 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 00Fh, 084h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 086h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 08Fh, 0FFh, 0FFh, 0FFh, 0FFh, 06Ah, 001h, 089h, 045h, 008h, 08Dh, 045h, 0A8h, 0FFh, 0FFh, 0FFh, 0FFh, 015h
	o_p_npmask_transform_eff_ignore1 	db    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    0,    0
	r_p_npdata_transform_eff_ignore1 	db 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 00Fh, 081h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 086h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 08Fh, 0FFh, 0FFh, 0FFh, 0FFh, 06Ah, 001h, 089h, 045h, 008h, 08Dh, 045h, 0A8h, 0FFh, 0FFh, 0FFh, 0FFh, 015h
	r_p_npmask_transform_eff_ignore1 	db    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    0,    0
	r_p_npcout_transform_eff_ignore1 	dd   39
	
	o_p_npdata_transform_eff_ignore2	db 083h, 0ECh, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0F1h, 033h, 0DBh, 039h, 05Eh, 008h, 0FFh, 00Fh, 084h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 00Fh, 084h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 04Eh, 010h
	o_p_npmask_transform_eff_ignore2	db    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    1,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0
	r_p_npdata_transform_eff_ignore2	db 083h, 0ECh, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0F1h, 033h, 0DBh, 039h, 05Eh, 008h, 0FFh, 00Fh, 081h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 00Fh, 084h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 04Eh, 010h
	r_p_npmask_transform_eff_ignore2	db    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    1,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0
	r_p_npcout_transform_eff_ignore2	dd	 37
	
	o_p_npdata_transform_eff_ignore3	db 08Bh, 0CBh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 00Fh, 084h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 04Bh, 010h, 080h, 0B9h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 00Fh, 085h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 043h, 008h
	o_p_npmask_transform_eff_ignore3	db    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    1,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    0
	r_p_npdata_transform_eff_ignore3	db 08Bh, 0CBh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 00Fh, 081h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 04Bh, 010h, 080h, 0B9h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 00Fh, 085h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 043h, 008h
	r_p_npmask_transform_eff_ignore3	db    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    1,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    0
	r_p_npcout_transform_eff_ignore3	dd	 35

	o_p_npdata_transform_eff_ignore4	db 08Bh, 0F1h, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 075h, 009h, 038h, 045h, 00Ch, 00Fh, 084h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 04Eh, 010h, 080h, 0B9h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 00Fh, 085h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 046h, 008h
	o_p_npmask_transform_eff_ignore4	db    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    1,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    0
	r_p_npdata_transform_eff_ignore4	db 08Bh, 0F1h, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 070h, 009h, 038h, 045h, 00Ch, 00Fh, 081h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 04Eh, 010h, 080h, 0B9h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 00Fh, 085h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 046h, 008h
	r_p_npmask_transform_eff_ignore4	db    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    1,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    0
	r_p_npcout_transform_eff_ignore4	dd	 40
	
	o_p_npdata_transform_eff_ignore5	db 085h, 0FFh, 08Bh, 0D8h, 074h, 0FFh, 08Bh, 046h, 00Ch, 080h, 0B8h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 075h, 0FFh, 08Bh, 088h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 075h
	o_p_npmask_transform_eff_ignore5	db    0,    0,    0,    0,    0,    1,    0,    0,    0,    0,    0,    1,    1,    1,    1,    1,    0,    1,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    0
	r_p_npdata_transform_eff_ignore5	db 085h, 0FFh, 08Bh, 0D8h, 074h, 0FFh, 08Bh, 046h, 00Ch, 080h, 0B8h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 075h, 0FFh, 08Bh, 088h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 0EBh
	r_p_npmask_transform_eff_ignore5	db    0,    0,    0,    0,    0,    1,    0,    0,    0,    0,    0,    1,    1,    1,    1,    1,    0,    1,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0,    0
	r_p_npcout_transform_eff_ignore5	dd	 33
	
	o_s_npdata_transform_eff_ignore6 	db 08Bh, 0C8h, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 074h, 01Bh, 08Bh, 006h, 08Bh, 0CEh, 0FFh, 050h, 004h, 08Bh, 010h
	o_s_npmask_transform_eff_ignore6 	db    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
	r_s_npdata_transform_eff_ignore6 	db 08Bh, 0C8h, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 0EBh, 01Bh, 08Bh, 006h, 08Bh, 0CEh, 0FFh, 050h, 004h, 08Bh, 010h
	r_s_npmask_transform_eff_ignore6 	db    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
	r_s_npcout_transform_eff_ignore6 	dd   20
	
	o_s_npdata_transform_eff_ignore7 	db 08Bh, 0C8h, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 08Bh, 0CEh, 074h, 017h, 08Bh, 006h, 0FFh, 050h, 004h, 08Bh, 010h
	o_s_npmask_transform_eff_ignore7 	db    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
	r_s_npdata_transform_eff_ignore7 	db 08Bh, 0C8h, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h, 08Bh, 0CEh, 0EBh, 017h, 08Bh, 006h, 0FFh, 050h, 004h, 08Bh, 010h
	r_s_npmask_transform_eff_ignore7 	db    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
	r_s_npcout_transform_eff_ignore7 	dd   20

	o_p_npdata_durability_colorize 	db 08Dh, 04Dh, 0F0h, 0C6h, 045h, 0FCh, 000h, 0FFh, 0D6h, 08Bh, 0CFh, 0FFh, 0D3h, 083h, 0F8h, 00Ah, 00Fh, 087h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 0CFh
	o_p_npmask_durability_colorize	db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0
	r_p_npdata_durability_colorize 	db 08Dh, 04Dh, 0F0h, 0C6h, 045h, 0FCh, 000h, 0FFh, 0D6h, 08Bh, 0CFh, 0FFh, 0D3h, 0B9h, 038h, 007h, 080h, 063h, 0FFh, 0D1h, 077h, 033h, 074h, 038h
	r_p_npmask_durability_colorize 	db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
	r_p_npcout_durability_colorize 	dd   24
	
	
	o_p_npdata_PLI_CaptionMgrRender_1	db 063h, 000h, 06Fh, 000h, 064h, 000h, 065h, 000h, 02Eh, 000h, 069h, 000h, 06Eh, 000h, 074h, 000h, 065h, 000h, 072h, 000h, 066h, 000h, 061h, 000h, 063h, 000h, 065h, 000h, 02Eh, 000h, 050h, 000h
																		db 04Ch, 000h, 049h, 000h, 05Fh, 000h, 043h, 000h, 061h, 000h, 070h, 000h, 074h, 000h, 069h, 000h, 06Fh, 000h, 06Eh, 000h, 04Dh, 000h, 067h, 000h, 072h, 000h, 052h, 000h, 065h, 000h, 06Eh, 000h
																		db 064h, 000h, 065h, 000h, 072h, 000h, 02Eh, 000h, 031h, 000h, 000h
	o_p_npdata_PLI_CaptionMgrRender_2	db 063h, 000h, 06Fh, 000h, 064h, 000h, 065h, 000h, 02Eh, 000h, 069h, 000h, 06Eh, 000h, 074h, 000h, 065h, 000h, 072h, 000h, 066h, 000h, 061h, 000h, 063h, 000h, 065h, 000h, 02Eh, 000h, 050h, 000h
																		db 04Ch, 000h, 049h, 000h, 05Fh, 000h, 043h, 000h, 061h, 000h, 070h, 000h, 074h, 000h, 069h, 000h, 06Fh, 000h, 06Eh, 000h, 04Dh, 000h, 067h, 000h, 072h, 000h, 052h, 000h, 065h, 000h, 06Eh, 000h
																		db 064h, 000h, 065h, 000h, 072h, 000h, 02Eh, 000h, 032h, 000h, 000h
	o_p_npdata_PLI_CaptionMgrRender_3	db 063h, 000h, 06Fh, 000h, 064h, 000h, 065h, 000h, 02Eh, 000h, 069h, 000h, 06Eh, 000h, 074h, 000h, 065h, 000h, 072h, 000h, 066h, 000h, 061h, 000h, 063h, 000h, 065h, 000h, 02Eh, 000h, 050h, 000h
																		db 04Ch, 000h, 049h, 000h, 05Fh, 000h, 043h, 000h, 061h, 000h, 070h, 000h, 074h, 000h, 069h, 000h, 06Fh, 000h, 06Eh, 000h, 04Dh, 000h, 067h, 000h, 072h, 000h, 052h, 000h, 065h, 000h, 06Eh, 000h
																		db 064h, 000h, 065h, 000h, 072h, 000h, 02Eh, 000h, 033h, 000h, 000h
	o_p_npmask_PLI_CaptionMgrRender		db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
																		db		0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
																		db		0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
	r_p_npdata_PLI_CaptionMgrRender		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
																		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
																		db 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h, 000h
	r_p_npcout_PLI_CaptionMgrRender		dd	 75
	
	o_p_npdata_adv_party_swap_party	db 06Ah, 001h, 053h, 0C7h, 045h, 0FCh, 008h, 000h, 000h, 000h, 053h, 0E9h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 04Dh, 0ECh, 068h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h
	o_p_npmask_adv_party_swap_party	db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0
	r_p_npdata_adv_party_swap_party	db 06Ah, 001h, 053h, 0C7h, 045h, 0FCh, 008h, 000h, 000h, 000h, 053h, 0E9h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 04Dh, 0ECh, 068h, 004h, 007h, 080h, 063h, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h
	r_p_npmask_adv_party_swap_party	db    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0
	r_p_npcout_adv_party_swap_party dd	 32
	
	o_p_npdata_adv_party_swap_adver	db 083h, 04Dh, 0FCh, 0FFh, 08Bh, 0C8h, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 0E9h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 04Dh, 0ECh, 068h, 0FFh, 0FFh, 0FFh, 0FFh, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h
	o_p_npmask_adv_party_swap_adver	db    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    1,    1,    1,    1,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0,    0
	r_p_npdata_adv_party_swap_adver	db 083h, 04Dh, 0FCh, 0FFh, 08Bh, 0C8h, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 0E9h, 0FFh, 0FFh, 0FFh, 0FFh, 08Bh, 04Dh, 0ECh, 068h, 05Fh, 003h, 080h, 063h, 0FFh, 015h, 0FFh, 0FFh, 0FFh, 0FFh, 084h, 0C0h
	r_p_npmask_adv_party_swap_adver	db    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0
	r_p_npcout_adv_party_swap_adver dd	 32	
	
	o_p_npdata_prop_targeting	db 0FFh, 0D3h, 083h, 065h, 0FCh, 000h, 08Bh, 0CEh, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 083h, 0F8h, 001h, 08Dh, 04Dh, 0DCh, 075h, 007h, 068h, 0FFh, 0FFh, 0FFh, 0FFh, 0EBh, 005h
	o_p_npmask_prop_targeting	db    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0
	r_p_npdata_prop_targeting	db 0FFh, 0D3h, 083h, 065h, 0FCh, 000h, 08Bh, 0CEh, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 083h, 0F8h, 001h, 08Dh, 04Dh, 0DCh, 075h, 007h, 068h, 0ACh, 007h, 080h, 063h, 0EBh, 005h
	r_p_npmask_prop_targeting	db    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
	r_p_npcout_prop_targeting	dd	 28
	
	; 노기노기 초상화 간소화
	o_p_npdata_portrait_simply db 08Bh, 0F1h, 033h, 0DBh, 089h, 05Dh, 0F0h, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 038h, 058h, 0FFh, 00Fh, 084h, 0FFh, 0FFh, 0FFh, 0FFh, 039h, 09Eh, 0FFh, 0FFh, 0FFh, 0FFh, 00Fh
	o_p_npmask_portrait_simply db    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    1,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0
	r_p_npdata_portrait_simply db 08Bh, 0F1h, 033h, 0DBh, 089h, 05Dh, 0F0h, 0E8h, 0FFh, 0FFh, 0FFh, 0FFh, 038h, 058h, 0FFh, 00Fh, 081h, 0FFh, 0FFh, 0FFh, 0FFh, 039h, 09Eh, 0FFh, 0FFh, 0FFh, 0FFh, 00Fh
	r_p_npmask_portrait_simply db    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,    1,    1,    0,    0,    1,    0,    0,    1,    1,    1,    1,    0,    0,    1,    1,    1,    1,    0
	r_p_npcout_portrait_simply dd   28