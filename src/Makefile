#
# Copyright 2020 Rinwasyu
# 
# This file is part of ray-marching.
# 
# Ray-marching is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# Ray-marching is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
# 

.PHONY: all clean

PROG := main
CC := gcc
CFLAGS := -Wall -W -std=c99 -Ofast -march=native -fopenmp -flto
LDFLAGS := $(CFLAGS) -lm
SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.d)

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC)  $(CFLAGS) -MD -c $< -o $@

clean:
	rm -rf *.o *.d $(PROG)

-include $(DEPS)