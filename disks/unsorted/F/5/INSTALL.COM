:� ��	&,!\ ~#�1B9&,� <��+&,� �4
$1	� �c   INSTALLATION PROGRAM  VER 3.5B
$?	� �q
$n	� Ý   Copyright (C) 1982 RSP Inc.
$|	� ë
$�	� ù
$�	� ��
$�	� ��
$�	� �
ARE FULL SCREEN OPERATIONS WANTED (Y/N)? $�	� � �_�Y�%�2� Ã!>�2� �0
$-	� �>
$;	� �L
$I	� �Z
$W	� �h
$e	� �v
$s	� á             TERMINAL OPTION 
$�	� ��                 MENU #1
$�	� ��
$�	� �A -ADDS VIEWPOINT      M -HEATH 89         
$�	� �GB -ADM-31              N -HP 125           
$	� ÀC -ADM-3A              O -HP 2621          
$R	� ùD -ACCESS              P -INTERCOLOR       
$�	� ��E -APPLE ///           Q -KAYPRO II        
$�	� �+F -APPLE II 40 COL     R -NEC PC-8000/1    
$�	� �dG -CROMEMCO 3102       S -NS ADVANTAGE     
$6	� ÝH -DIALOG 81           T -OSBORNE I        
$o	� ��I -EAGLE AVL           U -PERKIN ELMER 11  
$�	� �J -EPSON QX-10         V -SANYO MBC 3000   
$�	� �HK -GNAT-SYSTEM 10      W -SOROC            
$	� ÁL -HAZELTINE 1500                          
$S	� Ï
$�	� í     X - MENU #2
$�	� ��     Y - MODIFY PREVIOUS INSTALLATION
$�	� �     Z - USER SUPPLIED TERMINAL COMMANDS
$�	� �$
$!	� �FSELECT TERMINAL TYPE: $/	� � �_�Yʸ
�Zʿ�X�r
�>��n
$k	� �<�#�g�á             TERMINAL OPTION 
$�	� ��                 MENU #2
$�	� ��
$�	� �
A -SPERRY UTS 40      M -XEROX 820     
$�	� �?B -SUPERBRAIN                          
$	� �tC -TELEVIDEO                           
$J	� éD -TOSHIBA T100                        
$	� ��E -TOSHIBA T250                        
$�	� �F -TRS-80 (FMG)                        
$�	� �HG -TRS-80 II (P&T)                     
$	� �}H -TRS-80 III                          
$S	� òI -VECTOR GRAPHICS                     
$�	� ��J -VISUAL-100                          
$�	� �	K -VPD-80                              
$�	� �Q	L -VT-100                              
$'		� �_	
$\		� �}	     X - MENU #1
$j		� ð	     Y - MODIFY PREVIOUS INSTALLATION
$�		� ��	     Z - USER SUPPLIED TERMINAL COMMANDS
$�		� ��	
$�		� �

$�		� �$
SELECT TERMINAL TYPE: $
	� � �_�Yʸ
�Zʿ�X�]
�>��L

$I
	� �=�E
��%��Aڰ+�W>�ڰ+���À
���Jʮ
> 2� ���Aڰ+�!�,_ ~#fo"�,â
x��~#×
� R ͗
Ã!>�2� ��À
>�2�,��







$�
	� ��
MODIFY EXISTING SPECS ROUTINE

$�
	� �3FOR THIS METHOD, YOU WILL NEED THE HEX OR
$	� �iDECIMAL CODES THAT CAN BE SENT FROM YOUR
$>	� ãCOMPUTER TO THE VIDEO TERMINAL TO CONTROL IT
$t	� ñ
$�	� ��TYPE "Y" IF YOU WISH TO CONTINUE
$�	� � �_�Y°+��
$�	� �






$	� �OWILL YOU BE ENTERING COMMANDS AS HEX OR DECIMAL?$	� �]
$Z	� ØTYPE "D" FOR DECIMAL   OR "H" FOR HEXADECIMAL
$h	� � �_�Dʶ�H�W>�2�,��






$�	� �COMMANDS ARE ENTERED AS A SEQUENCE OF NUMBERS
$�	� �;TYPE A CARRIAGE RETURN TO END A SEQUENCE

$	� �I
$F	� �u1 -     DELETE A CHAR SEQUENCE
$T	� í2 -     DIRECT CURSOR POSITIONING SEQUENCE
$�	� ��3 -     CLEAR AND HOME SCREEN COMMAND
$�	� �4 -     BRIGHT/STD VIDEO COMMANDS
$�	� �?5 -     DIM/REVERSE VIDEO COMMANDS
$	� �l6 -     INITIALIZATION SEQUENCE
$J	� Ï7 -     EXIT SEQUENCE
$w	� ��8 -     RESET TO STANDARD VIDEO MODE
$�	� ��9 -     ALTER SCREEN SIZE
$�	� ��
$�	� � SELECT ITEM TO CHANGE
$	� �U ANY CHAR OTHER THAN 1 - 9 TERMINATES SESSION
$%	� �c
$`	� � �1ڃ!�:҃!  �1_��_!����Cͧ�C�S�C͢�C͠�C̀�C�P�C͊�C� �C��






$�	� ��USER SUPPLIED SPECS ROUTINE

$�	� �3FOR THIS METHOD, YOU WILL NEED THE HEX OR
$	� �iDECIMAL CODES THAT CAN BE SENT FROM YOUR
$>	� ãCOMPUTER TO THE VIDEO TERMINAL TO CONTROL IT
$t	� ñ
$�	� ��THE CODES (OR SEQUENCES) THAT YOU WILL NEED ARE:$�	� ��
$�	� �	
$	� �2     DELETE A CHAR SEQUENCE
$	� �g     DIRECT CURSOR POSITIONING SEQUENCE
$=	� Î     CLEAR SCREEN COMMAND
$r	� ô     HOME CURSOR COMMAND
$�	� ��          (CLEAR AND HOME CAN BE COMBINED)
$�	� �     OPTIONAL: BRIGHT/DIM COMMANDS OR
$�	� �R               VIDEO/REVERSE COMMANDS
$*	� �`
$]	� ÎTYPE "Y" IF YOU WISH TO CONTINUE
$k	� � �_�Y°+è
$�	� ��






$�	� ��WILL YOU BE ENTERING COMMANDS AS HEX OR DECIMAL?$�	� �
$		� �GTYPE "D" FOR DECIMAL   OR "H" FOR HEXADECIMAL
$	� � �_�D�e�H�>�2�,�w






$h	� òCOMMANDS ARE ENTERED AS A SEQUENCE OF NUMBERS
$�	� ��TYPE A CARRIAGE RETURN TO END A SEQUENCE

$�	� �ͧ͢͠�S̀�P͊� Ã!�
$	� �NNOW ENTER THE CODES FOR CHARACTER DELETION
$!	� :�,��l!� F#�1+��*��-âTHIS IS THE SEQUENCE "BACKSPACE,SPACE,BACKSPACE"
$o	� ��ON MOST TERMINALS  IF THIS IS TRUE FOR YOUR
$�	� � TERMINAL, THEN TYPE "Y"
$�	� �
$	� � �_�Y�!�  s#�'�?






$0	� �pENTER THE CHARACTER DELETE SEQUENCE
$J	� Ê(3 BYTE MAX)
${	� >!� �M):�,2� ��*�V�ù






$�	� ��--- DIRECT CURSOR POSITIONING ---

$�	� �#THE CURSOR CONTROL SEQUENCE IS USUALLY A 3 
$�	� �YTO 4 BYTE SEQUENCE. THE FIRST ONE OR TWO
$.	� ÐBYTES ARE USUALLY FIXED AND THE REMAINING
$d	� ��BYTES CONTAIN THE LINE AND COLUMN NUMBERS
$�	� ��
$�	� �ARE THE CURSOR ADDRESSES SINGLE BINARY BYTES OR
$�	� �TSEVERAL ASCII DIGITS?, TYPE A "Y" IF THEY ARE BINARY
$	� �2� � �_�Y�q>2� �w
$t	� ìNOW, ENTER THE POSITION IN THE SEQUENCE
$�	� ��THAT HOLDS THE COLUMN NUMBER
$�	� :�,����CURRENT VALUE = $�	� :� <́+�
$	� �!*=2� �#
$ 	� �YNEXT, ENTER THE POSITION IN THE SEQUENCE
$.	� ÁTHAT HOLDS THE LINE NUMBER
$d	� :�,���äCURRENT VALUE = $�	� :� <́+ù
$�	� �!*=2� ��
$�	� ��


$�	� �MANY TERMINALS ADD A CONSTANT TO THE LINE
$�	� �PAND COLUMN NUMBERS. ENTER THE CONSTANT BIAS
$"	� �oFOR YOUR TERMINAL
$[	� :�,�ʮÒCURRENT VALUE = $�	� :� ́+æ
$�	� �!*2� þ


$�	� ��NOW ENTER THE SKELETON FOR THE DIRECT CURSOR
$�	� �/COMMAND. ENTER A ZERO IN THE PLACES WHERE
$	� �WCOLUMN AND LINE NUMBERS GO
$:	� �r(11 BYTE MAX)
$b	� :�,�ʍ!� F#�1+��*�>!� �M):�,2� ��*§�ì


$�	� ��---- DIM/BRIGHT    VIDEO/REVERSE VIDEO ----
$�	� ��


$�	� �*ENTER THE COMMAND THAT WILL SWITCH TO
$	� �VHIGH INTENSITY OR NORMAL VIDEO
$5	� �p(5 BYTE MAX)
$a	� :�,�ʋ!� F#�1+��*�>!� �M):�,2� ��*¢�ê


$�	� ��ENTER THE COMMAND THAT WILL SWITCH TO
$�	� �	LOW INTENSITY OR REVERSE VIDEO
$�	� �#(5 BYTE MAX)
$	� :�,��>!� F#�1+��*�>!� �M):�,2� ��* ��]


$V	� Î---- CLEAR AND HOME COMMAND(S) ----
$h	� à


$�	� ��ENTER THE COMMAND(S) THAT WILL CLEAR THE
$�	� �SCREEN AND PLACE THE CURSOR IN THE UPPER
$�	� �5LEFT CORNER OF THE TERMINAL
$	� �P(11 BYTE MAX)
$@	� :�,��k!� F#�1+��*�>!� �M):�,2� ��*�S�Ê


$�	� üENTER THE COMMANDS TO BE ISSUED WHEN
$�	� ��ENTERING THE FULL-SCREEN EDITING MODE
$�	� �(IF ANY)
$�	� � (11 BYTE MAX)
$	� :�,��;!� F#�1+��*�>!� �M):�,2� ��*��Z


$S	� ÌENTER THE COMMANDS TO BE ISSUED WHEN
$e	� þLEAVING THE FULL-SCREEN EDITING MODE
$�	� ��
$�	� �SUGGESTION: USE DIRECT CURSOR POSITIONING
$�	� �?TO PUT CURSOR ON THE BOTTOM LINE OF THE SCREEN
$	� �Z(11 BYTE MAX)
$J	� :�,��u!� F#�1+��*�>!� �M):�,2� ��*�P�Ô


$�	� ��ENTER THE COMMAND THAT WILL SWITCH TO
$�	� ��STANDARD INTENSITY OR NORMAL VIDEO
$�	� �5 TO RESET THE SCREEN AFTER FULL SCREEN OPERATIONS
$ 	� �O (5 BYTE MAX)
$@ 	� :�,��j !� F#�1+��*�>!� �M):�,2� ��*�Å 
$� 	� é ENTER THE SCREEN WIDTH
$� 	� :�,��� �� CURRENT VALUE = $� 	� :� ́+�� 
$� 	� �!*2� �� 
$� 	� �/!NEXT, ENTER THE NUMBER OF LINES ON THE SCREEN
$� 	� :�,��n!�R!CURRENT VALUE = $A!	� :� ́+�f!
$c!	� �!*2� �z!
$w!	� �É!
$�!	� ×!
$�!	� ��!CHANGE MACRO, DATE, DELIMITER, ETC. (Y/N)? $�!	� � �_�Y�%(>&2� >�2� �2� 2� ��!
$�!	� �"
$"	� �5"ENTER A CHARACTER TO BE USED FOR
$"	� �d"INDICATING MACROS OR A RETURN FOR
$@"	� Ô"DEFAULT CHARACTER OF AMPERSAND (&) :$o"	� � ��ʫ"2� ñ"
$�"	� ÿ"
$�"	� ��"TYPE A RETURN IF THE ERROR CORRECTION
$�"	� �##DIALOGUE IS TO BE USED OR ANY OTHER
$�"	� �N#KEY IF NO DIALOGUE IS WANTED  :$.#	� � ���f#�2� �l#
$i#	� �z#
$w#	� È#
$�#	� ê#ENTER OPERATING SYSTEM$�#	� ø#
$�#	� ��#   A - CP/M 2.2
$�#	� ��#   B - TurboDOS SYSTEM
$�#	� �$
$$	� �$
$$	� �>$CHOOSE AN OPERATING SYSTEM : $ $	� � �_�A�r$�B�m$�f#>�2� �r$>�2� 2� �r$>�2� �x$
$u$	� Æ$
$�$	� ó$ENTER A DRIVE NAME FROM (A TO P) $�$	� ��$WHERE THE OVERLAY AND HELP
$�$	� �%FILE WILL BE ON, OR HIT (RETURN) $�$	� �+%FOR THE DEFAULT DRIVE
$%	� �X%WHERE dBASE II IS EXECUTED FROM: $6%	� � �_���v%> 2� �Ë%���@ڰ+�W>�ڰ+z2� ��Ñ%
$�%	� ß%
$�%	� !� ~� �&��%DATE FORMAT IS MM/DD/YY,  CHANGE TO DD/MM/YY ? (Y/N) : $�%	� � �_��d&�Y�d&>�2� �d&�F&DATE FORMAT IS DD/MM/YY, CHANGE TO MM/DD/YY ? (Y/N) : $&	� � �_��d&�Y�d&> 2� �j&
$g&	� �x&
$u&	� ñ&YOUR CURRENT FULL SCREEN ENTRY DELIMITERS :
$�&	� ��&   LEFT  DELIMITER "$�&	� :� _� ��&"$�&	� ��&
$�&	� �'   RIGHT DELIMITER "$ '	� :� _� �+'"$)'	� �9'
$6'	� �G'
$D'	� �{'DO YOU WANT TO CHANGE DELIMITERS? (Y/N) $R'	� � �_�Y�%(Õ'
$�'	� þ'   CHANGE LEFT  DELIMITER TO $�'	� � ��%(�
�%(2� ���'
$�'	� �(   CHANGE RIGHT DELIMITER TO $�'	� � ��%(�
�%(2� �%(�1(



$((	� �p(TYPE "Y" TO SAVE, ANY OTHER KEY TO ABORT INSTALL : $<(	� � �_�Y�%)ê(
SAVING INSTALLATION PARAMETERS
$�(	� :4,�24,�2F,&,� >2F,&,� *�,R "�,*�,~��)�@G#~�@O#"�,x�_ !� �y�O !� 	w#w��(>2F,&,� &,� �  �B)
ABORTING INSTALLATION
$()	� �  "�,2�,�2�,�])
$Z)	� Â)ENTER CONTROL CODE BYTE  $h)	� :�,<o& ú)�������	ڝ)
 	�|�Ĕ){�0__� ����͔)��): $�)	� *�,~́+��) $�)	� �!*�*��)*�,w*�,#"�,!�,4!�,5�*�W)�*
$*	� �*
$*	� :�,�!H,� s#�(*
H,>� :I,���*:J,�Y�:�,�ʌ*�z*!  ���G�]*�_�0������k*���
�O ))))	�S*J,�P*}ڹ*|�¹*<}�ê*  ��0���
?�)�))�	O 	Ó*!J,͏*}|�¹*<}�ÿ*
$�*	� ��*ERROR IN INPUT, RE-ENTER
$�*	� �!*!  7���*

$�*	� �+IS THIS CORRECT (Y/N) $+	� � �_�Y����9+
$6+	� �Y+CURRENT SEQUENCE :
$D+	� ��x��~��́+�r+
$o+	� ��#�c+�:�,�ʨ+�ä+�͖+��Ɛ'�@'_� ͍+��o& ͔)���+
ILLEGAL PARAMETER$�+	� �  ��+
$�+	� !',��^� ��#��+�, FILE IS NOT ON THE DEFAULT DRIVE
$�+	� �   DBASE   COM                      ENT SEQUENCE :
$D+	� ��x��~��́+�r+
$o+	� ��#�c+�:�,�ʨ+�ä+�͖+��Ɛ'�@'_� ͍+��o& ͔)���+
ILLEGAL PARAMETER$   	�  �2�.d.�8F6^0R2�7�3k-�/-.�1�1]/88�3�6�1�-�7k-�61?7�5�5�20D4�0Y1
/Y1K3  �~         ~   ~   ~   ~         ~~��                PP SDEX    =         (   )   (   *         (=7                 PP HLKJ    X Y                     KH       X7Y                 PP 
    Y         p   q   q   E         qY7                 PP     =                                  =7                   PP 
    =         (   )   (             (=7                 PP 
    =                                  =7                   PP 
                                  .                 P0P 
    =         "   !   "             "=7                 PP 
    Y                               Y7                  PP S\D]E^X_    =         (   )   )   �         =7                   (P 
                                                           PP 
    Y                                  Y7                   PP HFKJWO  
[000;000H [7m [0m [0m 
[2J[1;1H [0m[23;1H           PP[DCAB    =         (   )   (             (=7                 �P 
 P &a000y000C&dB &d@ &d@ 
HJH     &a23y1C              PP DCAB    Y                           E         Y7                   PP DCAB   (                           (?                PP 
    Y             0A               Y7                  PP HLKJ    =                                     =7                   PP 
    =         C4 C0 C0 *         C0=7               PP 
    =                           *         =7                   PP HLKJ                                                                         @          =         (   )   )   *         =7                   PP HLKJZJBL    =         )   (   (   *         (=7                 PP HLKJ    =         (   )   )   *         (=7                 PP HLKJZJBL    =         (   )   )   *         (=7                 PP HLKJNIVPZJBL    ~         ~   ~   ~   ~~       ~ ~                PP 
                                                       PP 
    Y         PB  PA  PB  E         rY7                 PP 
    =                                 =7                   PP 
    =         (   )   (   *         (=7                 PP HLKJ    =         Aj Ak a             =7 a                PP 
    F                        E         F7                   PP      =                                     =7                    PP 
    =         )   (   (   *        =7                   PP 
                                   