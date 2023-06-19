#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/inotify.h>
#include <unistd.h>

size_t EVENT_SIZE = sizeof(struct inotify_event);

int main(){	
	long BUFF_LEN = EVENT_SIZE * 16 * 1024;
	int length=0, i=0,
		fd=0, wd=0;
	char buffer[BUFF_LEN];

	fd = inotify_init();
	
	if(fd < 0) perror("ERROR: fd < 0\n");

	wd = inotify_add_watch(fd, "/home/volodymyr_malynovskyi/Documents/Linux/C_repeat/memory/NewDir2", IN_MODIFY | IN_CREATE | IN_DELETE);
	length = read(fd, buffer, BUFF_LEN);
		

	if(length < 0) perror("ERROR: length < 0\n");
	
	while(i < length){
		struct inotify_event *event = (struct inotify_event*) &buffer[i];
		
		if(event->mask & IN_CREATE){
			printf("The file %s was craeted.\n", event->name);
		}
		if(event->mask & IN_DELETE){	
			printf("The file %s was deleted.\n", event->name);
		}
		if(event->mask & IN_MODIFY){
			printf("The file %s was modified.\n", event->name);
		}
		i += EVENT_SIZE + event->len;
	}
	inotify_rm_watch(fd, wd);
	close(fd);
	return 0;

}
