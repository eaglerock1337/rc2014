!  9"1�> ��82��"JOB V1.5
$�:] � �.>	�8��͟�g!  "v���L�X���_> �8����:�_> �8�  !e ~� ʐ}����.JOB file not found$�!}~#�!� ��2���/½#"�~2�� �#ï����ҽ+�*t~�����~#�7��7��7�� ���	��+���J�*r�*t~��rs#r#"t�� :q�"�#~#��e�"�+��1#�+~#���1��"r�p��"�E~�,�E#~�7�?�> 2q~�"�2q#�:��/�:� �;�:� �;�!�  #����J͢��y�ʗx��*r�s#r�������~����oT] :q�"ʿ}��e~����#î}��e~��e�"��#ÿ#���~���e�� ��	��,����ȷ�:��/�\ ʹ�!)�	�y��6 ʹ���>�8�}͆�}G��|x�>�8x/<������ƀ�����o& ����"~2J#~2K#~#fo"��2L�>!)�8!\ $w#�o������~4��	�����!� ~�¯#~� ¯#~#�##�¯+~��ð������!  6 �>�8<������>ô*v#"v*x�*r"xs#r#�# ��   ���
����w#ʹ����"r�q��"r�q����:��/�,�i�G:��L�;>�G_ <2!� ~����> 2*�|�+"�>>\ �8�7�?�:��:����ړ=2��>�*�~#"��|ʁ��>��>	�8�>
�8:�!�"��7�?�: =����Memory full$>�5<��:\2m�2m>�5<���Directory full$*x|�ʜ^#V#�"x�~��)�D*v+"v*x|��3^#V#�"x��*v+"v��>M���O� �����~#2z"{!� "}�2� Ew#�W�����^��ڮ�^ʀ�\�@ڮ� Ү�$:��/>$ʝ���e�$£�����]���"�e�0��eG�]~#����ö>�5����Disk full$!z~=7�w*{~#"{?�!� 4��*}w#"}�:z�7�~?��
�ro& )�^#V+�~#���#���0��:?����
�)��8�#�0��|��)���0�S��>�S>
�_>�8���a��{��_���Parameter$��Too many parameters:$��Line too long:$��Job file empty$��Control character$�>	�8�>	�8*v�)�L>�5�   error on line number: $
*$!YD 6 #x��!�"t!��"�"�!�"r>�22�2��;>	�8*��
How to use JOB:

JOB<CR>            : print this message
JOB /<CR>          : interactive mode
JOB /<cmd lines>   : use SUMMARY mode
JOB <FILE> <PARMS> : as standard SUBMIT.COM, but JOB will search
for A:file.JOB after the default disk if no drive was specified,
and then as a component of "JOBS.LBR" if not already found.
The SUB file is created on "A:",  thus JOB may be used while any
drive is the default.  Parameters may be delimited by commas and
may be "quoted strings". An initial line beginning with ";;" can
be used to specify default params (0..9) at execution time.

In "/" (interactive) mode,  JOB will prompt you a line at a time
for the "SUBMIT" job input. Logical lines may be combined on the
same input line by separating them with "|".  Example:
  A>JOB /STAT|DIR
specifies two commands on the same input line.

Submitted jobs may nest...JOB inserts ahead of an existing job.

To insert a control character into the output, prefix it with
a "^" ("^^" for real "^").
$ JOBS    LBR                        $$$     SUB                                                                                                                                                                                                                                                                                                                                                                                                                                       