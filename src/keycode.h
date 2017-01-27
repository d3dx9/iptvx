/*

   Copyright 2017   Jan Kammerath

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

*/

#ifndef KEYCODE_H
#define KEYCODE_H

/*
   Converts a SDL keycode to a JS keycode
   @param      sdl_keycode    The SDL keycode
   @return                    Returns the JS keycode value
*/
int keycode_convert_sdl_to_js(int sdl_keycode);

#endif