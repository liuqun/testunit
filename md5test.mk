
local_src_files := md5test.c
local_obj_files := $(local_src_files:.c=.o)
local_exec_files := md5test
local_exec_files := $(addsuffix $(EXEEXT), $(local_exec_files))

$(local_exec_files): $(local_obj_files)
md5test.o: CFLAGS+=$(shell pkg-config libcrypto --cflags)
md5test: LIBS+=$(shell pkg-config libcrypto --libs)
#-------------------------------------------------

exec_files += $(local_exec_files)
src_files += $(local_src_files)
obj_files += $(local_obj_files)

