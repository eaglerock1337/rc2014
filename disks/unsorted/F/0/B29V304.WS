.PN
.FO Page #
.PC 5
.MT 3
.MB 3

















============================================================================

                       BBBB          222         9999   
                       B   B        2   2       9    9  
                       B   B            2       9    9  
                       BBBB            2         99999  
                       B   B          2              9  
                       B   B         2               9  
                       BBBB         22222        9999   

============================================================================
 


 


                                  B29.COM
                  Version 3.04     Written by Gary Conway
                     Infinity Design Concepts  (c) 1985,86


     MEMBER : KKUG - Kentuckiana Kaypro Users Group
              IEEE - Institute of Electrical and Electronics Engineers, INC.
              PCCL - Portable Computer Club of Louisville

















�                                  FORWARD

     Thi� progra��i� �n Newswee� work-alik� an� � mus� paus� her� t� giv� �
credi�� wher� credi� i� due�� Anyon� wh� ha� use� Newswee� t� an� degre� a� �
al� ha� surel� realize� al� o� th� wor� an� effor� tha� ha� gon� int� th� �
creatio� o� thi� excellen� program�� Mr�� Ran� ha� certainl� don� � fin� jo� �
i� th� developmen� o� Newsweep�� Th� layou� alon� an� i� particula� th� ide� �
o� taggin� file� fo� mas� operation� i� on� o� th� fines�� features�� Th� �
layou�� o� B2� i� ver� simila� an� � mus� offe� � heart� thank-yo�� t� Dav� �
Rand�� who�� � hav� neve� eve� spoke� t� an� t� th� creator/� o� SWEEP�� th� �
original�� ɠ hav� bee� � religou� use� o� Newswee� fo� som� tim� an� bein� �
on� wh� canno� leav� wel� enoug� alone�� � firs� wante� t� ad� � rea� tim� �
cloc� featur� an� pagebreak� i� printin� t� Newsweep�� Afte� som� tim� o� �
playing�� ɠ decide� t� writ� m� ow� versio� o� � swee� progra� addin� som� �
features� Th� mai� feature� tha� � hav� adde� ar� liste� below:

     <1> Pagebreaks and expanded TAB's when printing files.
     <2> Print tagged files.
     <3> Printing of .COM files.
     <4> Prints filename on printout.
     <5> Printer strings.
     <6> Printing multiple copies.
     <7> Clean abort of print.
     <8> A HEX dump facility for viewing .COM files (DDT type Dump).
     <9> An easier to use Set file attribute function.
    <10> If the user tries to View a .COM file, it will simply give a HEX
         dump to the screen, the same goes for printing a .COM file
    <11> Real time display.
    <12> Moving files from one user area to another (without copying).
    <13> Library File Sweep Mode (View,Print,Extract).


     Yo� wil� notic� th� lac� o� � squeez�  facility� Th� reaso� fo� thi� i� �
quit� simple�� A� present�� � don'� kno� ho� t� squeez� files� Tha� i� o� m� �
agend� o� thing� t� learn�� Whe� � do�� � wil� incorporat� thi� int� th� �
progra� also�� Thi� progra� i� writte� wit� th� standar� CP/� assembler� An� �
comment� o� suggestion� wil� gladl� b� accepte� a� wel� a� � $10.0� donatio� �
i� yo�� enjo� usin� th� program�� Thi� progra� i� copyrighte� an� i� give� �
freel� int� th� publi� domain� however� n� par� o� thi� progra� i� permitte� �
t� b� use� i� conjunctio� wit� an� sal� whatsoever�� withou� prio� writte� �
consen� fro� th� author.


CP/M 3.0 and MP/M

     B2� versio� 3.�x i� th� firs� versio� t� b� compatibl� wit� CP/� 3.� an� �
MP/M.

Sort to Disk Option GONE !

     Versio� 3.� ha� los� th� sor� t� dis� option�� I� becam� � proble�� o� �
man�� machine� wit� har� disk� t� kee� al� o� th� director�  informatio� i� �
concurren�� RA͠ wit� B2� �� it� buffer� an� CP/͠ itself�� I�� wa� almos� �
impossibl� t� us� o� � bulleti� boar� syste� wit� � har� driv� alon� wit� �
th� RA� residen� bulleti� boar� softwar� � BY� etc�� )� If� fo� example� yo� �
hav� � har� dis� wit� 100� director� entries�� thi� wil� requir� 32� o� RA� �
t� hol� th� entir� directory�� couple� wit� th� fac� tha� B2� use� 14ˠ an� �
ha� a� 8� genera� purpos� buffer�� thi� account� fo� 54� o� � 64� RA� syste� �
an� coul� easil� clobbe� CP/M�� I� orde� t� mak� th� progra� a� universa� a� �
possible, I reluctantly decided to remove the sort to disk option.�

     Send Comments To:   Infinity Design Concepts
                         Gary Conway
                         1052 Parkway Drive
                         Louisville, Kentucky  40217
                         (502)634-0054


     - OR -  E-MAIL c/o
                         The SoftStone RCP/M   (FOG #24)
                         Louisville, Kentucky
                         (502)241-4109
               Leave Message to My Attention OR to the SYSOP








                            ERRORS CAUGHT BY B29 

     1� BDO� erro� o� X�� selec� -   Whe� selectin� � ne� drive�� B29� check� �
                                     firs�� t� se� i� th� driv� i� indee� o� �
                                     lin� befor� actuall� makin� th� driv� �
                                     selection�� Thi� i� don� wit� � BIO� �
                                     cal� a� oppose� t� � BDOӠ cal� t� �
                                     avoi䠠 th堠 inheren�� BDOӠ� checkin� �
                                     procedure.
     2��COP٠ t�sam� drive/use� -   Thi� i� somethin� tha�� mos�� peopl� �
                and filename         would not wish to do and B29 will not
                                     allow this.
     3��AN٠operatio� o� a� R/� fil� - I� th� use� trie� t� cop� ove� o� �
                                     delet� an�R/Ϡfile��th�use� i� advised
                                     o� thi� conditio� an� i� aske� whethe� or
                                     not to proceed with the operation.
     4�� N�director� spac� lef� -   I� � cop� operatio� i� attempte� t� � disk
                                     tha� ha� n� director� spac�available� the
                                     user is advised of this and the copy is 
                                     aborted.
     5�� N�spac� lef� o� dest��d� - I� � cop� operatio� i� attempte� t� � dr.
                                     that has no space left or if the drive
                                     runs out of space before the copy is 
                                     complete, the copy is aborted.

                               G E N E R A L

          1.   Upper or lower case may be used throughout the program.
          2.   Carriage return aborts any operation or question.
          3.   Any operation or prompt may be aborted by simply hitting
               <RETURN>.
          4.   Any attempt to VIEW,PRINT or DUMP Squeezed files, will cause
               the file to be unsqueezed first.
          5.   Viewing an .LBR file will envoke Library File Sweep Mode. 



�          
Th� listin� belo� show� whic� function� operat� o� singl� file� an� whic� �
functions operate on severa� files.

          SINGLE OPERATIONS                       MASS OPERATIONS

          1. Single file copy                     1. Wildcard tag
          2. Hexdump file                         2. Mass copy
          3. View file                            3. Erase tagged files
          4. Rename file                          4. Move files to new user
          5. Tag file                             5. Print tagged files
          6. Untag file                           6. Unsqueeze files
          7. Delete file                          7. Rename files
          8. Find file      

                             -----------------

ACKNOWLEDGEMENTS:
     ɠ woul� lik� t� than� severa� folk� fo� thei� undyin� participatio� i� �
th� ever-importan� beta-testin� stage� a� wel� a� actin� a� source� o� idea� �
an� bouncin� board� fo� m� ow� ideas�� � woul� lik� t� than� Jerr�� Taylo� �
(Mr�� Find-a-bu� himself)�� an� Cur� Edward� fo� idea� a� wel� a� testin� o� �
th� ol� OZZY� � woul� lik� t� exten� � heart� remot� thank� t� Stev� Sander� �
fo� hi� ide� o� puttin� th� installatio� parameter� a� th� star�� o� th� �
program� whic� ultimatel� le� t� th� creatio� o� th� B29INST.CO� program� a� �
wel� a� hi� supplyin�  th� sourc� t� Unsqueezin� files� � woul� als� lik� t� �
expres� m� appreciatio� t� Ernes� Dryde� (SYSO� FOG#23� fo� hi� ai� i� th� �
implementatio� o� CP/͠ 3.� an� fo� hi� ai� i� debuggin� th� 3.�� versio� �
also.

     INVOKING B29
There are several ways to call B29.

A0>B29 *          logs all users on the default drive
A0>B29 B          logs drive B in the current user
A0>B29 B3         logs drive B in user 3
A0>B29 B12        logs drive B in user 12
A0>B29 B*         logs drive B all files in all users
A0>B29 B7*        logs drive B user 7 and displays all files in all users
A0>B29 B12;*.COM  logs B, user 12 and all .COM files
A0>B29 B*;*.COM   logs all users and all .COM files


     Th� botto�� lin� i� tha� yo� ma� us� jus� abou� an� comman� lin� tha� �
makes sense to you. All CP/M wildcards are also valid.
     I� a� invali� driv� designatio� i� given�� the� th� defaul� driv� an� �
use� ar� logge� in�� Afte� B2� begin� executio� an� i� ha� rea� an� sorte� �
th� dis� directory�� th� use� i� aske� i� h� wishe� t� writ� th� sorte� �
director� bac� t� th� disk�� I� th� use� choose� t� d� this�� the� th� dis� �
director�� wil� b� writte� bac� t� th� dis� i� � sorte� an� packe� fashion� �
Th� packin� featur� remove� al� delete� filename� fro� th� directory�� Thi� �
i� th� onl�� poin�� i� th� progra� wher� th� use� ma�� writ� th� sorte� �
director� bac� t� th� disk�� On� migh� as� wh� no� d� i� ever� tim� tha� yo� �
lo� i� � ne� disk�� Thi� wa� � poin� o� som� though� an� discussio� an� th� �
resultan�� decisio� t� offe� thi� onl� onc� wa� mad� i� a� effor�� t� kee� �
thi� selectio� i� th� real� o� option� rathe� tha� � nuisance�� I� i� no� �
tha�� ofte� tha� on� wishe� t� sor� an� pac� th� dis� directory�� Onc� th� �
director�� i� sorte� t� disk�� the� ther� i� n� wa� t� recove� an�� ERAse� �
file� wit� UNERA.CO� o� othe� suc� programs�� Also� afte� th� dis� director� �
i� sorted�� whe� th� use� use� th� DI� comman� i� CP/M� h� wil� se� � sorte� ��directory.
     Th� sor� forma� i�  USE� AREA� FILENAME� FIL� EXTENSION� Thi� forma� i� �
no� quit� th� sam� a� NSWEEP�� Th� resul� i� tha� al� file� wil� b� show� i� �
ascendin� use� area� wit� th� filename� subsorte� withi� eac� use� area� Th� �
potentia� proble� her� i� i� th� use� log� AL� user� an� ha� th� sam� fil� �
i� tw� o� mor� use� area� an� wishe� t� FIN� th� file� Th� FIN� comman� wil� �
only find the first occurence.

                            --------------------

     RETAG FILES              <A> command
Thi� optio� wil� reta� file� tha� wer� previouls� tagge� befor� an�� mas� �
operation.

                            -------------------

     FORWARD ONE FILE         <CR) or <SP> command
     
     Thi� comman� wil� mov� t� th� nex� fil� i� th� list�� Carriag� retur� �
will move one file only, while the space bar will move forward continously.

                            -------------------


     BACK ONE FILE            <B> command
Thi� optio� move� th� curso� bac� on� fil� i� th� directory�� Whe� a�� th� �
beginning of the directory, the cursor is returned to the last file.

                            -------------------




     COPY SINGLE FILE         <C> command
Thi� optio� wil� cop� � singl� fil� t� an� drive/user�� I� onl� th� driv� o� �
driv� an� use� code� ar� given�� the� th� fil� i� copie� wit� th� sam� name� �
I� a� attemp� i� mad� t� cop� t� th� sam� driv� an� use� a� th� origina� �
file, then the copy is simply not made.
     Valid entries are:  B
                         B3
                         B12
                         B3:
                         B3;MICKEY
                         B12:MICKEY.MSE
     o� an� combinatio� thereof�� N� wildcard� ar� permitte� here�� I� n� �
filenam� i� given�� the� th� fil� i� copie� t� th� destinatio� drive/use� �
wit� th� filenam� unchanged�� Th� "Verify� option�� i� selected� wil� rerea� �
th� destinatio� fil� an� chec� th� CR� valu� wit� th� valu� o� th� origina� �
file and report any mismatch.

                             -----------------


     DELETE CURRENT FILE      <D> command
Thi� optio� wil� delet� th� curren� file�� I� th� fil� ha� bee� se� t� R/O� �
the� anothe� messag� i� give� an� th� use� i� aske� i� h� stil� wishe� t� �
delet� th� file�� I� h� does�� h� mus� answe� wit� 'Y� o� 'y� an� th� fil� �
wil� b� deleted�� otherwis� ther� i� n� deletion� � carriag� retur� alon� a� �
an� o� th� prompt� wil� abor� th� delet� operation� Th� fil� wil� b� delete� �
fro� th� dis� director� a� wel� a� fro� th� director� i� RA� tha� B2�� uses� ��Th� fil� numbe� tha�� ha� bee� assigne� t� tha� fil� wil� n� longe� b� �
displaye� o� th� scree� an� th� remainin� file� wil� no� b� renumbered� Thi� �
wa� don� purposel�� s� tha� i� � fil� i� delete� an� the� late� yo�� as� �
yoursel� wha� yo� ha� jus� deleted�� yo� wil� hav� som� ide� becaus� o� th� �
missin� fil� number. If you must renumber, just log the drive in again.

                            --------------------

     ERASE TAGGED FILES       <E> command
Thi� optio� wil� onl� delet� th� tagge� files� wherea� Newswee� woul� delet� �
eithe� tagge� o� untagge� files�� Afte� � grea�� dea� o� though�� an� �
discussion� � decide� no� t� includ� th� optio� t� delet� tagge� o� untagge� �
files�� becaus� thi� seem� to� dangerou� an� � personall� hav� onl� use� th� �
deletio� o� tagge� files�� I� th� fil� i� R/O�� th� use� wil� b� prompte� a� �
with DELETE.

                            --------------------

     FIND FILE                <F> command
Ente� an�� filespe� o� wildcar� filespe� an� th� progra� wil� locat� th� �
firs� fil� tha� complies�� Thi� ma� b� a� brie� a� � singl� characte� o� a� �
complex as wildcards will allow.
     
                         WS???.COM
                         ?-GETS.*
                         B*.*
                         B29*.C?? 
                         DD          etc...

                            --------------------

     LOG NEW DRIVE/USER/MASK       <L> command

     Thi� optio� allow� loggin� i� o� � ne� driv� o� use� o� mask�� Th� �
minimu� requiremen� i� th� driv� code�� Th� driv� cod� i� checke� t� se� i� �
tha� driv� i� o� line�� I� i� is�� processin� continues�� however�� i� i� i� �
not�� � messag� i� displaye� an� th� use� i� prompte� t� lo� i� � ne� �
drive/user�� Th� use� ma� wis� t� giv� th� use� numbe� o� '*� fo� al� user� �
o� � mas� suc� a� *.com� whic� wil� lo� i� al� .CO� files� Yo� ca� als� omi� �
th� driv� an� jus� giv� th� use� an� B2�  wil� lo� yo� int� tha�� use� o� �
the previously selected drive.

                         B
                         B: (or ;)
                         B0;*.COM
                         B12;WS??.COM 
                         B*:WS*.*       etc...

                            --------------------

     MENU           <?> or </> command
     Th� men� i� displaye� initiall� whe� B2� i� calle� an� eac� tim� � ne� �
driv� i� logged�� T� displa� th� men� a� an� othe� time�� hi� th� questio� �
mar� key�� Thi� ma� b� don� wit� o� withou� th� shif� key�� I� othe� words� �
the menu is called by '?' or '/'. Total disk space is also shown.

                           ---------------------

     TAG FILES           <T> command
     Thi� optio� tag� file� fo� mas� operation� copyin� o� settin� fil� ��attributes�� etc�� Th� scree� wil� sho� th� numbe� o� K-byte� tha� hav� bee� �
tagge� includin� th� currentl� tagge� file� I� invers� vide� i� active� the� �
thes� wil� b� show� i� invers� video�� Afte� taggin� th� curren� file�� th� �
curren� fil� pointe� i� incremente� t� th� nex� file.

                           ----------------------

     UNTAG FILES         <U> command
     Thi� comman� i� th� opposit� o� th� TA� comman� i� tha� i� untag� th� �
curren�� fil� (i� tagged� an� subtract� th� fil� siz� fro� th� numbe� o� �
tagged bytes and displays the new total.

                           ----------------------

     WILDCARD TAG        <W> command
     Thi� comman� allow� taggin� o� an� o� al� file� usin� CP/͠ wildcards� �
Any wildcards or even an unambigous filename may be used. See FIND command.

                           ----------------------

     MASS COPY           <M> command
     Thi� comman� wil� allo� copyin� o� al� tagge� file� t� an� driv� an� o� �
use� desired�� T� abor�� an� copy�� simpl� hi� an�� ke�� durin� th� cop� �
operatio� an� whe� th� curren� fil� i� finishe� copying� th� copyin� proces� �
wil� b� aborte� wit� � messag� t� tha� effect� Th� remainin� file� tha� hav� �
no� bee� copied�� wil� stil� b� tagged� Th� file� tha� hav� bee� copied� ar� �
pu� int� a� "alread� copied� state�� signifie� b� � "#� i� plac� o� "*"� B2� �
know� whic� file� ar� currentl� tagge� (*� o� "hav� bee� tagged"(#� an� ca� �
us� thi� fo� RETAGGING� Al� file� tha� ar� se� t� "#"� wil� b� retagge� whe� �
usin�th� (A)��reta� command��Thi� optio� als� allow� CRC��(se� SINGL� COPY)

                            --------------------

     VIEW FILE           <V> command

     Th� vie� comman� wil� prin� th� curren� fil� onscreen�� A� thi� poin� �
B2� will check to see if this is a squeezed file and unsqueeze if necessary.�
     I� yo� tr� t� vie� � .CO� file�� normall� yo� woul� se� garbag� o� th� �
screen�� howeve� B29� wil� catc� thi� an� d� � HEXDUM� instead��I� th� use�
trie� t� VIE� � Squeeze� file� th� fil� wil� b� unsqueeze� first.
     Th� fil� wil� b� presente� on� scree� a� � time�� T� vie�� th� nex� �
screen�� simpl� hi� <RETURN>�� fo� th� nex� line�� hi� -SPAC� BAR-� T� abor� �
hi�� "A� o� "a"�� Whe� finished�� th� scree� wil� b� cleare� an� yo� wil� b� �
returne� t� th� comman� mode.

     LIBRARY FILE SWEEP MODE
     
     B2� allow� viewing�� printin� an� extractin� file� fro� libraries� Thi� �
mod� i� invoke� b� positionin� th� curso� o� th� .LB� fil� an� the� usin� �
th� 'V�� command�� B2�� wil� intercep� th� vie� comman� an� initiat� th� �
Librar�� Fil� Swee� Mode�� Thi� mod� o� operatio� i� ver�� simila� t� th� �
Norma� Swee� Mode�� Th� scree� wil� clea� an� � lis� o� command� i� shown� �
Ther� i� n� taggin� allowe� here� Al� operation� dea� wit� singl� file� wit� �
th� exceptio� o� Extrac� All�� whic� wil� d� exactl�� that�� Al� o� th� �
commands in the menu operate the same as the Normal Sweep Mode commands.


                             ------------------

�     HEX DUMP FILE       <H> command

     Thi� comman� wil� tak� ANY� fil� an� dum� i� i� HE� forma� t� th� scree� �
fo� viewing�� Th� option� availabl� ar� th� sam� a� wit� th� VIEנ command� �
Squeeze� file� wil� automaticall� b� unsqueezed. This is a HEX/ASCII dump.

                           ______________________


     RENAME FILE         <E> command

     Th� renam� functio� wil� d� exactl� that�� Th� use� ma� giv� a� man� �
character� a� h� wishe� fo� th� ne� filenam� u� t� th� CP/� limi� o� eight� �
Th� extensio� i� (a� wit� CP/M� optional�� Thi� functio� als� check� t� se� �
i� th� ne� nam� alread� exist� o� th� dis� an� i� i� does�� � messag� i� �
issued and the rename is aborted.
     Th� renam� functio� als� ha� th� capabilit� t� d� wildcar� renaming� B� �
enterin� "*� i� respons� t� th� renam� prompt�� th� use� wil� b� aske� fo� �
th� OL� filenam� (*.COM�� WS*.� etc.� �� followe� b� th� NE� name� whic� ha� �
th� sam� synta� a� th� OL� filename�� FO� EXAMPLE� T� renam� al� o� th� .PR� �
file� t� .CMD�� th� use� woul� giv� *.PR� fo� th� OL� filenam� an� *.CM� fo� �
th� NE� name�� Thi� woul� caus� al� o� th� file� wit� th� .PR� extensio� o� �
that disk to be renamed using the .CMD extension.

                           ---------------------

     SPACE ON DISK       <S> command

     Th� checkspac� functio� wil� as� fo� whic� driv� t� chec� spac� on� �
chec� t� se� i� tha� driv� i� o� lin� an� i� i� is� th� byte� use� an� spac� �
remainin� ar� displayed�� I� th� selecte� driv� i� no� o� line�� th� use� i� �
prompte� fo� on� tha� is�� Th� bloc� siz� i� als� shown� Thi� i� th� minimu� �
file size on your machine.

                            --------------------
     MOVE FILES          <N> command

     Thi� functio� wil� mov� TAGGE� file� fro� on� use� are� t� another� �
Ther� i� n� copyin� involve� sinc� th� director� i� rea� an� scanne� fo� �
matche� o� th� tagge� file� an� the� th� use� numbe� i� change� t� th� ne� �
value.
NOTE�� Thi� comman� wil� OBVIOUSL� NO� move� file� t� � differen� use� are� �
       on another disk! Sorry, but you still have to copy...
                            ____________________

     SET FILE ATTRIBUTES      <Y> command

     Th� se� fil� attribute� functio� work� wit� TAGGE� file� only� Th� use� �
wil� firs�� ta� th� file� tha� ar� t� hav� certai� attribute� se� o� rese� �
an� the� select th� <Y� option�� B29� the� ask� whic� attribute� ar� t� b� �
se�� (SYSte��  DIRector��  R/Ϡ - rea� onl��  o� R/נ - rea� write)�� Th� �
attribute� tha�� hav� bee� se� wil� sho� u� a� invers� character� whe� B2� �
list� th� files� Thes� "status� bit� ar� locate� i� th� Extensio� portio� o� �
th� filename�� Th� firs� byt� o� th� extensio� ("C� i�  � ".COM� file� hold� �
th� R/� o� R/� attributes�� Th� "O� byte  hold� th� SY� o� DIҠ attributes� �
Wha�� reall� happen� her� i� tha� wit� norma� ASCI� character� th� hig� bi� �
i� zero�� I� yo� loo� a� a� ASCI� char� an� i� particular�� th� HEؠ values� �
yo� wil� notic� tha� th� char� stop� a� 7F� 7F(HEX)� i� binary� i� 01111111� �
th� hig� bi�� bein� zero�� Al� othe� ASCI� value� ar� smalle� tha� this� �
therefore�� thei� hig� bi� i� als� zero�� CP/� doe� no� us� thi� bi�� whe� ��openin� � file�� i� othe� words�� i� yo� giv� CP/� � filenam� wit� th� �
ASCIɠ characte� "A� whic� i� 41(HEX)�� yo� coul� jus� a� easil� hav� give� �
C1(HEX)�� 41(HEX� � 0100000� binar� an� C1(HEX� � 1100000� binary�� Th� onl� �
difference is the high order bit. 
     The purpose of these attributes is given below:

     SYS ....... The file will not be shown when using the CP/M  DIR command
     DIR ....... The file WILL be shown with the DIR command
     R/O ....... A read only file cannot be deleted or written to by any
                     normal CP/M commands.
     R/W ....... A read write file is the normal setting for CP/M files,
                     i.e. they can be read, written, deleted.
                           ----------------------
     PRINT TAGGED FILES       <P> command

     Th� prin�� file� comman� wil� prin� al� tagge� files�� Whe� th� PRIN� �
optio� i� selected�� th� use� i� prompte� fo� � printe� pitch�� Th� cod� fo� �
th� printe� i� us� shoul� hav� bee� installe� wit� B29INST.CO͠ prio� t� �
printing� i� orde� t� wor� correctly.(Se� Use� Patc� Section).Th� file� wil� �
b� printe� wit� th� filenam� printe� o� th� printou� a� th� top�� Tab� wil� �
b� expande� t� � characters�� Pagebreak� ar� als� provide� wit� 5� line� pe� �
pag� an� 8� column� pe� line�� Th� reta� comman� ca� als� the� b� use� t� �
reta� th� file� t� b� printe� agai� fo� thos� o� yo� tha� ar� int� printin� �
copie� fo� you� friends�� I� an� on� o� th� followin� fil� type� i� tagge� �
fo� print� the� wil� instea� b� HEXPRINT-ed.

                COM  REL  OVR  OVL  DBF  DAT  DTA  HEX  OBJ

     Also, their squeezed counterparts will be HEXPRINT-ed.

                             -----------------

Printing Multiple Copies

     Thi� optio� wil� allo� printin� u� t� 9� copie� o� an� give� file� Whe� �
yo� hav� positione� th� curso� besid� th� fil� tha� yo� wis� t� prin� copie� �
of�� hi�� th� � key�� Yo� wil� b� aske� ho� man� copie� t� prin�� an� th� �
printe� pitc� an� of� yo� go�� Not� tha� thi� doe� no� appl� t� tagge� file� �
as with normal printing, but only to the "Current File".
.pa�


                            * * * * * * * * * *

                          U S E R    P A T C H E S

                            * * * * * * * * * *

     Th� installatio� progra� (B29INST.COM� wil� instal� certai� feature� �
int� B29�� suc� a� printe� string� an� vide� sequences�� Whe� th� instal� �
progra� firs� come� up� th� use� i� prompte� fo� th� driv� wher� B29.CO� is� �
s� tha� B29INS� know� wher� t� pu� th� ne� codes�� Whe� th� driv� i� given� �
th� instal� progra� look� o� tha� driv� t� insur� tha� B29.CO͠ i� indee� �
there�� I� i� i� not� th� use� i� advise� o� thi� an� ha� th� opportunit� t� �
retry or abort.
     Whe� enterin� cod� sequence� wit� th� instal� program�� i�� i� no� �
necessar� t� loo� u� strang� an� ambiguou� codes� sinc� mos� manual� provid� �
th� code� i� severa� "dialects� anyway� thi� shoul� b� easy� Fo� example� i� �
th� printe� manua� say� tha� th� cod� fo� 1� cp� (ELIT� pitch� i� "ESà Q"� �
the� a� th� promp� fo� 1� cpi�� th� use� woul� hi� th� ESCap� ke� an� the� �
th� Ѡ key�� Al� o� th� code� t� b� installe� allo�� � maximu�� o� thre� �
characters�� whic� shoul� b� sufficien� fo� an� printer�� T� NUL� � string� �
us� th� -SPAC� BAR-� String� ca� b� NULLe� fo� thos� machine� no� havin� an� �
vide� sequences�� THE� CLOCK SHOULD ALSO BE MADE INACTIVE ON ALL � MACHINES �
EXCEP� TH� KAYRPO'� WIT� TH� REA� TIM� CLOC� BUILT-IN�� Th� "REMEMBE� CURSO� �
POSITION�� an� "STATU� LIN� PRESERVATION� function� shoul� b� NULLe� ou� fo� �
non-Kaypr� Rea� tim� Cloc� machine� a� well�� Thes� tw� code� ar� onl�� use� �
o� th� Kaypr� an� ca� serv� n� purpos� o� an� othe� machines�� Th� "CUSTO� �
CURSOR�� shoul� als� b� disable� o� non-Kaypr� machine� sinc� thi� routin� �
call� specifi� ports�� i� wil� caus� B2� t� bom� o� othe� machines.Th� line� �
pe� pag� an� line� pe� scree� code� ca� b� entere� i� decimal�� however� �
B29INS� wil� no� allo� mor� tha� 6� line� pe� page� Th� defaul� value� show� �
i� th� installatio� progra� ar� take� fro� th� actua� CO� file�� tha� i� yo� �
ar� show� wha� th� curren� value� ar� befor� yo� chang� them.
     T� mak� th� change� permanent�� selec� th� "X� optio� an� yo� wil� b� �
prompted for Saving the changes or Aborting the session.


NOTE:
     Gemin� 10�� an� Starmicronic� 10�� owners�� Th� printe� manua� i� �
misleadin� a� fa� a� th� printe� string� ar� concerned�� Th� boo� show� th� �
code� fo� characte� font� a� ES� "B� � an� chr$(27� chr$(66�� chr$(n)�� Th� �
"n� whe� use� fo� font� i� NO� a� ASCI� numbe� � o� � o� 3�� i� i� instea� � �
HE� � o� � o� 3�� Whe� usin� th� instal� progra� t� instal� thes� printers� �
yo� mus� us� ^� fo� 1�� ^� fo� � an� ^� fo� 3�� Example� T� instal� th� PIC� �
pitch string, you would type, ESC B ^A. 


NOTE:   ( Reiterating )
     I� yo� ar� no� usin� B2� o� � Kaypr� wit� th� built-i� clock�� yo� MUS� �
disabl� th� CLOCK�� CUSTO� CURSOR�� REMEMBE� CURSO� POSITION�� STATUӠ LIN� �
PRESERVATIO� option� wit� B29INST.CO� a� thes� option� ar� Kaypr� specific� 






�     Ok Hackers, here we go. A little prayer of thanks to DDT and off we go!


     Th� installatio� progra� (B29INST.COM)�� wil� instal� th� followin� �
byte� int� B29�� however�� th� tabl� belo� i� provide� a� � referenc� fo� �
those with other things in mind.

 
- PATCH LOCATION -       - LABEL - - BYTES AVAIL -    -FUNCTION-
 --------------------------------------------------------------------------
Decimal         Hex
 --------------------------------------------------------------------------
  361          0169      IRV OFF->     - 6 -      Inverse Video OFF
  377          0179       IRV 0N->     - 6 -      Inverse Video ON 
  392�         0188�      ST� ON-�     - ��-      Preserv�Statu� Line ON
  404          0194      STP OFF->     - 3 -      Preserve Status Line OFF
  419�         01A3�          R�-�     - � -      Remembe�Curren��Curs� Pos.
  427          01AB          GRC->     - 3 -      Go Last Rem. Curs. Pos.
  436          01B4           LP->     - 1 -      Lines per Page, Printer
  441          01B9           LS->     - 1 -      Lines on Screen
  446          01BE          CLS->     - 3 -      Clear Screen Code
  455          01C7         PICA->     - 3 -      Select 10 cpi
  465          01D1        ELITE->     - 3 -      Select 12 cpi
  476          01DC        COMPR->     - 3 -      Select 17 cpi
  487          01E7        CLOCK->     - 1 -      Clock Enable 00=y  C9=n
  495          01EF       CURSOR-��    - � -      Cus� Curso�Enabl�00=� C9=n 
 --------------------------------------------------------------------------

     Th� label� show� abov� ca� b� foun� i� th� firs� two secto�s o� �
th� .CO͠ fil� a� DDT'� HEX/ASCI� dum� wil� sho�� the�� up�� Th� byte� �
immediatel�� t� th� righ� o� th� "->� portio� o� eac� labe� i� wher� th� �
actua� cod� resides�� Th� patc� location� show�  represen�� the� startin� �
address of  the label��  Afte� patche�  ar�  complete�  yo� ca� sav� th� ne� 
imag� wit� ...
 

                            A0>SAV� 64 B29.COM.



     Ther� i� � tabl� i� th� CO� file�� whic� i� � lis� o� al� th� fil� �
extension� tha� wil� automaticall�  b� hexdumpe� i� th� use� trie� t� VIE� �
them. The list is marked in the file by an ASCII marker;

                               HEX-DUMP TABLE

     The table follows:

                    REL RQL COM CQM OBJ OQJ HEX HQX DTA 
                   DQA OVR OQR OVL OQL DBF DQF DAT DQT FF

     Th� byt� a� th� en� o� th� tabl� (FF� mus� remain�� a� i� i� th� en� o� �
tabl� delimite� fo� th� routin� tha� scan� th� table�� Th� space� show� �
betwee� th� extension� i� th� abov� tabl� ar� show� her� merel�� fo� �
clarity, as they are run together in the actual table in B29.COM.

     Th� extension� i� thi� tabl� ca� b� modifie� o� deleted�� bu� ther� ar� �
� fe� precautions�� I� i� wa� desire� t� remov� a� entr� fro� th� table�� i� �
i� no� possibl� simpl� t� delet� it�� I� a� entr� wa� delete� an� replace� �
wit� spaces�� the� an�� fil� tha� di� no�� hav� a� extensio� woul� b� ��hexdumped�� I� i� necessar� t� hav� th� tabl� contiguou� wit� n� space� an� �
a� FƠ byt� a� th� end�� T� remov� a� entr� fro� th� table�� i�� woul� b� �
easies�� t� mov� th� las� entr� t� th� spo� wher� a� entr� i� t� b� remove� �
an� the� mov� th� F� byt� t� th� ne� en� o� table�� Als� not� tha� th� tabl� �
i� no� expandable� i.e� d� no� mov� th� tabl� pas� th� F� byte!

     ɠ a� on� wh� canno� leav� wel� enoug� alon� an� alway� see� t� hav� t� �
ad� somethin� els� t� � program�� th� abov� informatio� i�  fo� thos� o� yo� �
wh� ar� o� th� sam� stat� o� menta� disorde� a� I�� I� yo� ar� int� som� �
seriou� patches�� � woul� b� intereste� i� wha� the� ar� a� wel� a� offe� �
assistanc� i� needed�� Thi� whol� progra� cam� abou� becaus� ɠ wante� t� �
patc� th� rea� tim� cloc� i� th� Kaypr� 4-8� int� NSWEEP�� consequentl�� � �
encourag� use� patchin� an� wil� hel� whe� asked.


                               W_A_R_N_I_N_G 
     I� yo� patc� int� th� wron� area�� a� wit� an� program�� B2� wil� no� �
work� I� an� o� th� copyrigh� message� ar� removed� B2� wil� issu� � messag� �
and exit and you will need a fresh copy of B29.


* EOF:B29xxx.WS
