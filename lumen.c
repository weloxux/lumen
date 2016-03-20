/* lumen - Simple X window manager
 * Copyright (C) 2016 Marnix Massar <marnix@vivesce.re>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>

void say(const char* e) {
	printf("lumen: %s\n", e);
}

void panic(const char* e) {
	say(e);
	exit(1);
}

int main() {
	Display* dis;
	XWindowAttributes attr;
	XButtonEvent start;
	XEvent ev;

	if(!(dis = XOpenDisplay(NULL))) {
		panic("Cannot open display");
	}

	say("Connected to display, starting");

	while(XNextEvent(dis, &ev)) {
		if (ev.type == KeyPress) {
			KeySym keysym = XKeycodeToKeysym(dis,ev.xkey.keycode,0);
			say("Got keypress");
			say(XKeysymToString(keysym));
		}
	}

	XCloseDisplay(dis);
	return 0;
}
