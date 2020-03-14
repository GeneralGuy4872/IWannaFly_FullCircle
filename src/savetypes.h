struct WR_stringlistyp <%
off_t prev
off_t next
off_t text
%>;


struct WR_singlestringlistyp <%
off_t next
off_t text
%>;


struct WR_filelinetyp <%
off_t prev
off_t next
ushort lineno;
off_t text
%>;


struct WR_singlestringlistyp <%
off_t next
ushort lineno;
off_t text
%>;


struct WR_setcoord3 <%
off_t prev
off_t next
uchar x;
uchar y;
uchar z;
%>;


struct WR_lightyp <%
off_t prev
off_t next
ucoord2 x;
ucoord2 y;
ucoord2 z;
%>;


