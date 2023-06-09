/*!
 *  \example appWebServerData.h
 *
 *  \brief
 *  Application Web Server File Data
 *
 *  \author
 *  KUNBUS GmbH
 *
 *  \date
 *  2022-05-19
 *
 *  \copyright
 *  Copyright (c) 2022, KUNBUS GmbH<br /><br />
 *  All rights reserved.<br />
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:<br />
 *  <ol>
 *  <li>Redistributions of source code must retain the above copyright notice, this
 *     list of conditions and the following disclaimer.</li>
 *  <li>Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.</li>
 *  <li>Neither the name of the copyright holder nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.</li>
 *  </ol>
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 *  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 *  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 *  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#ifndef APP_WEBSRV_DATA
#define APP_WEBSRV_DATA

#ifdef __cplusplus
extern "C" {
#endif

	static const char response_200_content_html[] = "HTTP/1.1 200 OK\r\nContent-type: text/html\r\n\r\n";

	static const char response_200_content_js[] = "HTTP/1.1 200 OK\r\nContent-type: text/javascript\r\n\r\n";

    static const char response_200_content_image[] = "HTTP/1.1 200 OK\r\nContent-type: image/x-icon\r\n\r\n";

	static const char response_404[] = "HTTP/1.1 404 Not Found\r\nContent-type: text/html\r\n\r\n"
    "<html>"
    "<head>"
    "<style>"
    "h1 {text-align: center;}"
    "h2 {text-align: center;}"
    "</style>"
    "<meta charset=\"utf-8\"/>"
    "<title>EtherNet/IP Adapter Stack Demo Webserver</title>"
    "</head>"
    "<h1>EtherNet/IP Adapter Stack Demo Webserver</h1>"
    "<h2>404 : Not Found </h2>"
    "</html>";

	static const char response_501[] = "HTTP/1.1 501 Not Implemented\r\nContent-type: text/html\r\n\r\n"
    "<html>"
    "<head>"
    "<style>"
    "h1 {text-align: center;}"
    "h2 {text-align: center;}"
    "</style>"
    "<meta charset=\"utf-8\"/>"
    "<title>EtherNet/IP Adapter Stack Demo Webserver</title>"
    "</head>"
    "<h1>EtherNet/IP Adapter Stack Demo Webserver</h1>"
    "<h2>501 : Not Implemented </h2>"
    "</html>";

	static const char main_html[] =
	"<!DOCTYPE HTML>"
	"<html>"
	"<head>"
	"<style>"
	"h1 {text-align: center;}"
	"table, th, td {"
	"border: 1px solid #dddddd;"
	"text-align: center;"
	"padding: 4px;"
	"margin-left: auto;"
	"margin-right: auto;"
	"}"
	"</style>"
	"<meta charset=\"utf-8\"/>"
	"<title>EtherNet/IP Adapter Stack Demo Webserver</title>"
	"<script src = \"main.js\"></script>"
	"</head>"
	"<h1>EtherNet/IP Adapter Stack Demo Webserver</h1>"
	"<body onload=\"getCpuLoad()\">"
	"<table id = \"Board Information\" width = \"50%\">"
	"<tr>"
	"<th>Parameter</th>"
	"<th>Value</th>"
	"</tr>"
	"<tr>"
	"<td id = \"r0c0\"></td>"
	"<td id = \"r0c1\">0 %</td>"
	"</tr>"
	"<tr>"
	"<td id = \"r1c0\"></td>"
	"<td id = \"r1c1\">0 %</td>"
	"</tr>"
	"<tr>"
	"<td id = \"r2c0\"></td>"
	"<td id = \"r2c1\">0 %</td>"
	"</tr>"
	"<tr>"
	"<td id = \"r3c0\"></td>"
	"<td id = \"r3c1\">0 %</td>"
	"</tr>"
	"<tr>"
	"<td id = \"r4c0\"></td>"
	"<td id = \"r4c1\">0 %</td>"
	"</tr>"
	"<tr>"
	"<td id = \"r5c0\"></td>"
	"<td id = \"r5c1\">0 %</td>"
	"</tr>"
	"<tr>"
	"<td id = \"r6c0\"></td>"
	"<td id = \"r6c1\">0 %</td>"
	"</tr>"
	"<tr>"
	"<td id = \"r7c0\"></td>"
	"<td id = \"r7c1\">0 %</td>"
	"</tr>"
	"<tr>"
	"<td id = \"r8c0\"></td>"
	"<td id = \"r8c1\">0 %</td>"
	"</tr>"
	"<tr>"
	"<td id = \"r9c0\"></td>"
	"<td id = \"r9c1\">0 %</td>"
	"</tr>"
	"<tr>"
	"<td id = \"r10c0\"></td>"
	"<td id = \"r10c1\">0 %</td>"
	"</tr>"
	"<tr>"
	"<td id = \"r11c0\"></td>"
	"<td id = \"r11c1\">0 %</td>"
	"</tr>"
	"<tr>"
	"<td id = \"r12c0\"></td>"
	"<td id = \"r12c1\">0 %</td>"
	"</tr>"
	"<tr>"
	"<td id = \"r13c0\"></td>"
	"<td id = \"r13c1\">0 %</td>"
	"</tr>"
	"<tr>"
	"<td id = \"r14c0\"></td>"
	"<td id = \"r14c1\">0 %</td>"
	"</tr>"
	"<tr>"
	"<td id = \"r15c0\"></td>"
	"<td id = \"r15c1\">0 %</td>"
	"</tr>"
	"<tr>"
	"<td id = \"r16c0\"></td>"
	"<td id = \"r16c1\">0 %</td>"
	"</tr>"
	"</table>"
	"</body>"
	"</html>";

	static const char main_js[] =
	"function getCpuLoad()"
	"{"
	"var cpuLoad = 0;"
	"function getCpuLoadComplete()"
	"{"
	"if(cpuLoad.readyState == 4)"
	"{"
	"if(cpuLoad.status == 200)"
	"{"
	"if(cpuLoad.responseText != null)"
	"{"
	"var rowsNum = 17;"
	"var id = \"\";"
	"var row = 0;"
	"var data = cpuLoad.responseText;"
	"const dataArray = data.split(\",\");"
	"for (let i = 0; i < dataArray.length; i = i + 2)"
	"{"
	"row = i/2;"
	"if (rowsNum > i/2)"
	"{"
	"id = \"r\" + row + \"c0\";"
	"document.getElementById(id).innerHTML = dataArray[i];"
	"id = \"r\" + row + \"c1\";"
	"document.getElementById(id).innerHTML = dataArray[i + 1];"
	"}"
	"}"
	"}"
	"}"
	"}"
	"}"
	"cpuLoad = new XMLHttpRequest();"
	"if(cpuLoad)"
	"{"
	"cpuLoad.open(\"GET\", \"/cpuLoad?id=\" + Math.random(), true);"
	"cpuLoad.responseType = \"text\";"
	"cpuLoad.onreadystatechange = getCpuLoadComplete;"
	"cpuLoad.send(null);"
	"}"
	"setTimeout('getCpuLoad()', 500);"
	"}";

    static const char favicon_ico[] =
    {
        0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x10, 0x10,
        0x10, 0x00, 0x01, 0x00, 0x04, 0x00, 0x28, 0x01,
        0x00, 0x00, 0x26, 0x00, 0x00, 0x00, 0x10, 0x10,
        0x00, 0x00, 0x01, 0x00, 0x08, 0x00, 0x68, 0x05,
        0x00, 0x00, 0x4e, 0x01, 0x00, 0x00, 0x28, 0x00,
        0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x20, 0x00,
        0x00, 0x00, 0x01, 0x00, 0x04, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80,
        0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x80, 0x00,
        0x00, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x80,
        0x00, 0x00, 0xc0, 0xc0, 0xc0, 0x00, 0x80, 0x80,
        0x80, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff,
        0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0xff, 0x00,
        0x00, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0xff,
        0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x07, 0x97, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x79, 0x97, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x07, 0x99, 0x97, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x79, 0x99, 0x99, 0x70, 0x00, 0x00, 0x07,
        0x77, 0x99, 0x97, 0x79, 0x97, 0x00, 0x00, 0x09,
        0x99, 0x99, 0x7f, 0xf7, 0x99, 0x70, 0x00, 0x79,
        0x99, 0x99, 0xf9, 0x97, 0x99, 0x97, 0x07, 0x99,
        0x99, 0x99, 0xf9, 0x9f, 0x99, 0x99, 0x79, 0x99,
        0x99, 0x99, 0xf9, 0x9f, 0x99, 0x99, 0x99, 0x99,
        0x99, 0x97, 0xf9, 0x9f, 0x79, 0x97, 0x00, 0x00,
        0x99, 0x97, 0xf7, 0x9f, 0x79, 0x90, 0x00, 0x00,
        0x99, 0x99, 0x7f, 0xf7, 0x99, 0x70, 0x00, 0x00,
        0x99, 0x99, 0x9f, 0x99, 0x00, 0x00, 0x00, 0x00,
        0x99, 0x99, 0x90, 0x99, 0x00, 0x00, 0x00, 0x00,
        0x99, 0x99, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x99, 0x99, 0x00, 0x00, 0x00, 0x00, 0xff, 0x8f,
        0xfc, 0xfd, 0xff, 0x0f, 0xfc, 0xfd, 0xfe, 0x0f,
        0xfc, 0xfd, 0xfc, 0x07, 0xfc, 0xfd, 0xe0, 0x03,
        0xfc, 0xfd, 0xe0, 0x01, 0xfc, 0xfd, 0xc0, 0x00,
        0xfc, 0xfd, 0x80, 0x00, 0xfc, 0xfd, 0x00, 0x00,
        0xfc, 0xfd, 0x00, 0x00, 0xfc, 0xfd, 0xf0, 0x01,
        0xfc, 0xfd, 0xf0, 0x01, 0xfc, 0xfd, 0xf0, 0x0f,
        0xfc, 0xfd, 0xf0, 0x4f, 0xfc, 0xfd, 0xf0, 0x7f,
        0xfc, 0xfd, 0xf0, 0xff, 0xfc, 0xfd, 0x28, 0x00,
        0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x20, 0x00,
        0x00, 0x00, 0x01, 0x00, 0x08, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80,
        0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x80, 0x00,
        0x00, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x80,
        0x00, 0x00, 0xc0, 0xc0, 0xc0, 0x00, 0xc0, 0xdc,
        0xc0, 0x00, 0xf0, 0xca, 0xa6, 0x00, 0xd4, 0xf0,
        0xff, 0x00, 0xb1, 0xe2, 0xff, 0x00, 0x8e, 0xd4,
        0xff, 0x00, 0x6b, 0xc6, 0xff, 0x00, 0x48, 0xb8,
        0xff, 0x00, 0x25, 0xaa, 0xff, 0x00, 0x00, 0xaa,
        0xff, 0x00, 0x00, 0x92, 0xdc, 0x00, 0x00, 0x7a,
        0xb9, 0x00, 0x00, 0x62, 0x96, 0x00, 0x00, 0x4a,
        0x73, 0x00, 0x00, 0x32, 0x50, 0x00, 0xd4, 0xe3,
        0xff, 0x00, 0xb1, 0xc7, 0xff, 0x00, 0x8e, 0xab,
        0xff, 0x00, 0x6b, 0x8f, 0xff, 0x00, 0x48, 0x73,
        0xff, 0x00, 0x25, 0x57, 0xff, 0x00, 0x00, 0x55,
        0xff, 0x00, 0x00, 0x49, 0xdc, 0x00, 0x00, 0x3d,
        0xb9, 0x00, 0x00, 0x31, 0x96, 0x00, 0x00, 0x25,
        0x73, 0x00, 0x00, 0x19, 0x50, 0x00, 0xd4, 0xd4,
        0xff, 0x00, 0xb1, 0xb1, 0xff, 0x00, 0x8e, 0x8e,
        0xff, 0x00, 0x6b, 0x6b, 0xff, 0x00, 0x48, 0x48,
        0xff, 0x00, 0x25, 0x25, 0xff, 0x00, 0x00, 0x00,
        0xff, 0x00, 0x00, 0x00, 0xdc, 0x00, 0x00, 0x00,
        0xb9, 0x00, 0x00, 0x00, 0x96, 0x00, 0x00, 0x00,
        0x73, 0x00, 0x00, 0x00, 0x50, 0x00, 0xe3, 0xd4,
        0xff, 0x00, 0xc7, 0xb1, 0xff, 0x00, 0xab, 0x8e,
        0xff, 0x00, 0x8f, 0x6b, 0xff, 0x00, 0x73, 0x48,
        0xff, 0x00, 0x57, 0x25, 0xff, 0x00, 0x55, 0x00,
        0xff, 0x00, 0x49, 0x00, 0xdc, 0x00, 0x3d, 0x00,
        0xb9, 0x00, 0x31, 0x00, 0x96, 0x00, 0x25, 0x00,
        0x73, 0x00, 0x19, 0x00, 0x50, 0x00, 0xf0, 0xd4,
        0xff, 0x00, 0xe2, 0xb1, 0xff, 0x00, 0xd4, 0x8e,
        0xff, 0x00, 0xc6, 0x6b, 0xff, 0x00, 0xb8, 0x48,
        0xff, 0x00, 0xaa, 0x25, 0xff, 0x00, 0xaa, 0x00,
        0xff, 0x00, 0x92, 0x00, 0xdc, 0x00, 0x7a, 0x00,
        0xb9, 0x00, 0x62, 0x00, 0x96, 0x00, 0x4a, 0x00,
        0x73, 0x00, 0x32, 0x00, 0x50, 0x00, 0xff, 0xd4,
        0xff, 0x00, 0xff, 0xb1, 0xff, 0x00, 0xff, 0x8e,
        0xff, 0x00, 0xff, 0x6b, 0xff, 0x00, 0xff, 0x48,
        0xff, 0x00, 0xff, 0x25, 0xff, 0x00, 0xff, 0x00,
        0xff, 0x00, 0xdc, 0x00, 0xdc, 0x00, 0xb9, 0x00,
        0xb9, 0x00, 0x96, 0x00, 0x96, 0x00, 0x73, 0x00,
        0x73, 0x00, 0x50, 0x00, 0x50, 0x00, 0xff, 0xd4,
        0xf0, 0x00, 0xff, 0xb1, 0xe2, 0x00, 0xff, 0x8e,
        0xd4, 0x00, 0xff, 0x6b, 0xc6, 0x00, 0xff, 0x48,
        0xb8, 0x00, 0xff, 0x25, 0xaa, 0x00, 0xff, 0x00,
        0xaa, 0x00, 0xdc, 0x00, 0x92, 0x00, 0xb9, 0x00,
        0x7a, 0x00, 0x96, 0x00, 0x62, 0x00, 0x73, 0x00,
        0x4a, 0x00, 0x50, 0x00, 0x32, 0x00, 0xff, 0xd4,
        0xe3, 0x00, 0xff, 0xb1, 0xc7, 0x00, 0xff, 0x8e,
        0xab, 0x00, 0xff, 0x6b, 0x8f, 0x00, 0xff, 0x48,
        0x73, 0x00, 0xff, 0x25, 0x57, 0x00, 0xff, 0x00,
        0x55, 0x00, 0xdc, 0x00, 0x49, 0x00, 0xb9, 0x00,
        0x3d, 0x00, 0x96, 0x00, 0x31, 0x00, 0x73, 0x00,
        0x25, 0x00, 0x50, 0x00, 0x19, 0x00, 0xff, 0xd4,
        0xd4, 0x00, 0xff, 0xb1, 0xb1, 0x00, 0xff, 0x8e,
        0x8e, 0x00, 0xff, 0x6b, 0x6b, 0x00, 0xff, 0x48,
        0x48, 0x00, 0xff, 0x25, 0x25, 0x00, 0xff, 0x00,
        0x00, 0x00, 0xdc, 0x00, 0x00, 0x00, 0xb9, 0x00,
        0x00, 0x00, 0x96, 0x00, 0x00, 0x00, 0x73, 0x00,
        0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0xff, 0xe3,
        0xd4, 0x00, 0xff, 0xc7, 0xb1, 0x00, 0xff, 0xab,
        0x8e, 0x00, 0xff, 0x8f, 0x6b, 0x00, 0xff, 0x73,
        0x48, 0x00, 0xff, 0x57, 0x25, 0x00, 0xff, 0x55,
        0x00, 0x00, 0xdc, 0x49, 0x00, 0x00, 0xb9, 0x3d,
        0x00, 0x00, 0x96, 0x31, 0x00, 0x00, 0x73, 0x25,
        0x00, 0x00, 0x50, 0x19, 0x00, 0x00, 0xff, 0xf0,
        0xd4, 0x00, 0xff, 0xe2, 0xb1, 0x00, 0xff, 0xd4,
        0x8e, 0x00, 0xff, 0xc6, 0x6b, 0x00, 0xff, 0xb8,
        0x48, 0x00, 0xff, 0xaa, 0x25, 0x00, 0xff, 0xaa,
        0x00, 0x00, 0xdc, 0x92, 0x00, 0x00, 0xb9, 0x7a,
        0x00, 0x00, 0x96, 0x62, 0x00, 0x00, 0x73, 0x4a,
        0x00, 0x00, 0x50, 0x32, 0x00, 0x00, 0xff, 0xff,
        0xd4, 0x00, 0xff, 0xff, 0xb1, 0x00, 0xff, 0xff,
        0x8e, 0x00, 0xff, 0xff, 0x6b, 0x00, 0xff, 0xff,
        0x48, 0x00, 0xff, 0xff, 0x25, 0x00, 0xff, 0xff,
        0x00, 0x00, 0xdc, 0xdc, 0x00, 0x00, 0xb9, 0xb9,
        0x00, 0x00, 0x96, 0x96, 0x00, 0x00, 0x73, 0x73,
        0x00, 0x00, 0x50, 0x50, 0x00, 0x00, 0xf0, 0xff,
        0xd4, 0x00, 0xe2, 0xff, 0xb1, 0x00, 0xd4, 0xff,
        0x8e, 0x00, 0xc6, 0xff, 0x6b, 0x00, 0xb8, 0xff,
        0x48, 0x00, 0xaa, 0xff, 0x25, 0x00, 0xaa, 0xff,
        0x00, 0x00, 0x92, 0xdc, 0x00, 0x00, 0x7a, 0xb9,
        0x00, 0x00, 0x62, 0x96, 0x00, 0x00, 0x4a, 0x73,
        0x00, 0x00, 0x32, 0x50, 0x00, 0x00, 0xe3, 0xff,
        0xd4, 0x00, 0xc7, 0xff, 0xb1, 0x00, 0xab, 0xff,
        0x8e, 0x00, 0x8f, 0xff, 0x6b, 0x00, 0x73, 0xff,
        0x48, 0x00, 0x57, 0xff, 0x25, 0x00, 0x55, 0xff,
        0x00, 0x00, 0x49, 0xdc, 0x00, 0x00, 0x3d, 0xb9,
        0x00, 0x00, 0x31, 0x96, 0x00, 0x00, 0x25, 0x73,
        0x00, 0x00, 0x19, 0x50, 0x00, 0x00, 0xd4, 0xff,
        0xd4, 0x00, 0xb1, 0xff, 0xb1, 0x00, 0x8e, 0xff,
        0x8e, 0x00, 0x6b, 0xff, 0x6b, 0x00, 0x48, 0xff,
        0x48, 0x00, 0x25, 0xff, 0x25, 0x00, 0x00, 0xff,
        0x00, 0x00, 0x00, 0xdc, 0x00, 0x00, 0x00, 0xb9,
        0x00, 0x00, 0x00, 0x96, 0x00, 0x00, 0x00, 0x73,
        0x00, 0x00, 0x00, 0x50, 0x00, 0x00, 0xd4, 0xff,
        0xe3, 0x00, 0xb1, 0xff, 0xc7, 0x00, 0x8e, 0xff,
        0xab, 0x00, 0x6b, 0xff, 0x8f, 0x00, 0x48, 0xff,
        0x73, 0x00, 0x25, 0xff, 0x57, 0x00, 0x00, 0xff,
        0x55, 0x00, 0x00, 0xdc, 0x49, 0x00, 0x00, 0xb9,
        0x3d, 0x00, 0x00, 0x96, 0x31, 0x00, 0x00, 0x73,
        0x25, 0x00, 0x00, 0x50, 0x19, 0x00, 0xd4, 0xff,
        0xf0, 0x00, 0xb1, 0xff, 0xe2, 0x00, 0x8e, 0xff,
        0xd4, 0x00, 0x6b, 0xff, 0xc6, 0x00, 0x48, 0xff,
        0xb8, 0x00, 0x25, 0xff, 0xaa, 0x00, 0x00, 0xff,
        0xaa, 0x00, 0x00, 0xdc, 0x92, 0x00, 0x00, 0xb9,
        0x7a, 0x00, 0x00, 0x96, 0x62, 0x00, 0x00, 0x73,
        0x4a, 0x00, 0x00, 0x50, 0x32, 0x00, 0xd4, 0xff,
        0xff, 0x00, 0xb1, 0xff, 0xff, 0x00, 0x8e, 0xff,
        0xff, 0x00, 0x6b, 0xff, 0xff, 0x00, 0x48, 0xff,
        0xff, 0x00, 0x25, 0xff, 0xff, 0x00, 0x00, 0xff,
        0xff, 0x00, 0x00, 0xdc, 0xdc, 0x00, 0x00, 0xb9,
        0xb9, 0x00, 0x00, 0x96, 0x96, 0x00, 0x00, 0x73,
        0x73, 0x00, 0x00, 0x50, 0x50, 0x00, 0xf2, 0xf2,
        0xf2, 0x00, 0xe6, 0xe6, 0xe6, 0x00, 0xda, 0xda,
        0xda, 0x00, 0xce, 0xce, 0xce, 0x00, 0xc2, 0xc2,
        0xc2, 0x00, 0xb6, 0xb6, 0xb6, 0x00, 0xaa, 0xaa,
        0xaa, 0x00, 0x9e, 0x9e, 0x9e, 0x00, 0x92, 0x92,
        0x92, 0x00, 0x86, 0x86, 0x86, 0x00, 0x7a, 0x7a,
        0x7a, 0x00, 0x6e, 0x6e, 0x6e, 0x00, 0x62, 0x62,
        0x62, 0x00, 0x56, 0x56, 0x56, 0x00, 0x4a, 0x4a,
        0x4a, 0x00, 0x3e, 0x3e, 0x3e, 0x00, 0x32, 0x32,
        0x32, 0x00, 0x26, 0x26, 0x26, 0x00, 0x1a, 0x1a,
        0x1a, 0x00, 0x0e, 0x0e, 0x0e, 0x00, 0xf0, 0xfb,
        0xff, 0x00, 0xa4, 0xa0, 0xa0, 0x00, 0x80, 0x80,
        0x80, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff,
        0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0xff, 0x00,
        0x00, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0xff,
        0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25,
        0x28, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x28,
        0x28, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x28, 0x28,
        0x28, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x28, 0x28,
        0x28, 0x28, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x25, 0x25, 0x25, 0x25, 0x28, 0x28, 0xf6,
        0xf6, 0x23, 0x28, 0x25, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x28, 0x28, 0x28, 0x28, 0x28, 0x23, 0x23,
        0x23, 0xf6, 0x23, 0x28, 0x25, 0x00, 0x00, 0x00,
        0x25, 0x28, 0x28, 0x28, 0x28, 0x28, 0x23, 0x28,
        0x28, 0xf6, 0x28, 0x28, 0x28, 0x25, 0x00, 0x25,
        0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x23, 0x28,
        0x28, 0xf6, 0x28, 0x28, 0x28, 0x28, 0x25, 0x28,
        0x28, 0x28, 0x28, 0x28, 0x28, 0xf6, 0xf6, 0x28,
        0x28, 0xf6, 0xf6, 0x28, 0x28, 0x28, 0x28, 0x28,
        0x28, 0x28, 0x28, 0x28, 0x28, 0xf6, 0xf6, 0x28,
        0x28, 0x23, 0xf6, 0x28, 0x28, 0x25, 0x00, 0x00,
        0x00, 0x00, 0x28, 0x28, 0x28, 0x28, 0x23, 0x23,
        0x28, 0x23, 0x28, 0x28, 0x28, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x28, 0x28, 0x28, 0x28, 0x28, 0x23,
        0x23, 0x23, 0x28, 0x28, 0x28, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x28, 0x28, 0x28, 0x28, 0x28, 0x23,
        0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x28, 0x28, 0x28, 0x28, 0x25, 0x00,
        0x28, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x28, 0x28, 0x28, 0x28, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x28, 0x28, 0x28, 0x28, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x8f,
        0x00, 0x00, 0xff, 0x0f, 0x00, 0x00, 0xfe, 0x0f,
        0x00, 0x00, 0xfe, 0x07, 0x00, 0x00, 0xe0, 0x03,
        0x00, 0x00, 0xe0, 0x01, 0x00, 0x00, 0xc0, 0x00,
        0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x01,
        0x00, 0x00, 0xf0, 0x01, 0x00, 0x00, 0xf0, 0x0f,
        0x00, 0x00, 0xf0, 0x4f, 0x00, 0x00, 0xf0, 0xff,
        0x00, 0x00, 0xf0, 0xff, 0x00, 0x00,
    };

#ifdef  __cplusplus 
}
#endif 

#endif // APP_WEBSRV_DATA
