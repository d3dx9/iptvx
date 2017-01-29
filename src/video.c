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

#include <vlc/vlc.h>

libvlc_instance_t * inst;
libvlc_media_player_t *mp;
libvlc_media_t *m;

int video_width;
int video_height;

/* initialise video playback and open media */
void iptvx_video_init(char *videofile, int width, int height){
	const char * const vlc_args[] = {
		"--no-xlib", /* tell VLC to not use Xlib */
	};

	/* create the VLC instance */
	inst = libvlc_new (sizeof(vlc_args) / sizeof(vlc_args[0]), vlc_args);

	/* open the defined media file */
	m = libvlc_media_new_location(inst,videofile);
	mp = libvlc_media_player_new_from_media(m);

	/* configure width and height of the video */
	video_width = width;
	video_height = height;
}

/* start the actual video playback */
void iptvx_video_play(libvlc_video_lock_cb lock, libvlc_video_unlock_cb unlock, 
						libvlc_video_display_cb display, void* context){	
	/* give it a little time to start up */
	usleep(1000000);
	libvlc_media_release (m);

	libvlc_video_set_callbacks(mp, lock, unlock, display, context);

	/* configure width and height of the video */
	libvlc_video_set_format(mp, "RV16", video_width, video_height, video_width*2);

	/* start playback */
	libvlc_media_player_play (mp);
}

/*
	Stops current playback
*/
void iptvx_video_stop(){
	/* tell vlc to stop current playback */
	libvlc_media_player_stop (mp);
}

void iptvx_video_free(){
	/* terminate the whole thing */
	libvlc_media_player_stop (mp);
	libvlc_media_player_release (mp);
	libvlc_release (inst);	
}