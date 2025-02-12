/* do not edit automatically generated by mc from mcStack.  */
/* This file is part of GNU Modula-2.

GNU Modula-2 is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GNU Modula-2 is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License along
with gm2; see the file COPYING.  If not, write to the Free Software
Foundation, 51 Franklin Street, Fifth Floor,
Boston, MA 02110-1301, USA.  */

#include "config.h"
#include "system.h"
#   if !defined (PROC_D)
#      define PROC_D
       typedef void (*PROC_t) (void);
       typedef struct { PROC_t proc; } PROC;
#   endif

#   include "GStorage.h"
#   include "Gmcrts.h"
#if defined(__cplusplus)
#   undef NULL
#   define NULL 0
#endif
#define _mcStack_H
#define _mcStack_C

#   include "GStorage.h"
#   include "GIndexing.h"
#   include "GM2RTS.h"

typedef struct mcStack__T1_r mcStack__T1;

typedef mcStack__T1 *mcStack_stack;

struct mcStack__T1_r {
                       Indexing_Index list;
                       unsigned int count;
                     };


/*
   init - create and return a stack.
*/

extern "C" mcStack_stack mcStack_init (void);

/*
   kill - deletes stack, s.
*/

extern "C" void mcStack_kill (mcStack_stack *s);

/*
   push - an address, a, onto the stack, s.
          It returns, a.
*/

extern "C" void * mcStack_push (mcStack_stack s, void * a);

/*
   pop - and return the top element from stack, s.
*/

extern "C" void * mcStack_pop (mcStack_stack s);

/*
   replace - performs a pop; push (a); return a.
*/

extern "C" void * mcStack_replace (mcStack_stack s, void * a);

/*
   depth - returns the depth of the stack.
*/

extern "C" unsigned int mcStack_depth (mcStack_stack s);

/*
   access - returns the, i, th stack element.
            The top of stack is defined by:

            access (s, depth (s)).
*/

extern "C" void * mcStack_access (mcStack_stack s, unsigned int i);


/*
   init - create and return a stack.
*/

extern "C" mcStack_stack mcStack_init (void)
{
  mcStack_stack s;

  Storage_ALLOCATE ((void **) &s, sizeof (mcStack__T1));
  s->list = Indexing_InitIndex (1);
  s->count = 0;
  return s;
  /* static analysis guarentees a RETURN statement will be used before here.  */
  __builtin_unreachable ();
}


/*
   kill - deletes stack, s.
*/

extern "C" void mcStack_kill (mcStack_stack *s)
{
  (*s)->list = Indexing_KillIndex ((*s)->list);
  Storage_DEALLOCATE ((void **) &(*s), sizeof (mcStack__T1));
  (*s) = NULL;
}


/*
   push - an address, a, onto the stack, s.
          It returns, a.
*/

extern "C" void * mcStack_push (mcStack_stack s, void * a)
{
  if (s->count == 0)
    {
      Indexing_PutIndice (s->list, Indexing_LowIndice (s->list), a);
    }
  else
    {
      Indexing_PutIndice (s->list, (Indexing_HighIndice (s->list))+1, a);
    }
  s->count += 1;
  return a;
  /* static analysis guarentees a RETURN statement will be used before here.  */
  __builtin_unreachable ();
}


/*
   pop - and return the top element from stack, s.
*/

extern "C" void * mcStack_pop (mcStack_stack s)
{
  void * a;

  if (s->count == 0)
    {
      M2RTS_HALT (-1);
      __builtin_unreachable ();
    }
  else
    {
      s->count -= 1;
      a = Indexing_GetIndice (s->list, Indexing_HighIndice (s->list));
      Indexing_DeleteIndice (s->list, Indexing_HighIndice (s->list));
      return a;
    }
  ReturnException ("../../gcc-git-devel-modula2/gcc/m2/mc/mcStack.def", 20, 1);
  __builtin_unreachable ();
}


/*
   replace - performs a pop; push (a); return a.
*/

extern "C" void * mcStack_replace (mcStack_stack s, void * a)
{
  void * b;

  b = mcStack_pop (s);
  return mcStack_push (s, a);
  /* static analysis guarentees a RETURN statement will be used before here.  */
  __builtin_unreachable ();
}


/*
   depth - returns the depth of the stack.
*/

extern "C" unsigned int mcStack_depth (mcStack_stack s)
{
  return s->count;
  /* static analysis guarentees a RETURN statement will be used before here.  */
  __builtin_unreachable ();
}


/*
   access - returns the, i, th stack element.
            The top of stack is defined by:

            access (s, depth (s)).
*/

extern "C" void * mcStack_access (mcStack_stack s, unsigned int i)
{
  if ((i > s->count) || (i == 0))
    {
      M2RTS_HALT (-1);
      __builtin_unreachable ();
    }
  else
    {
      return Indexing_GetIndice (s->list, i);
    }
  ReturnException ("../../gcc-git-devel-modula2/gcc/m2/mc/mcStack.def", 20, 1);
  __builtin_unreachable ();
}

extern "C" void _M2_mcStack_init (__attribute__((unused)) int argc,__attribute__((unused)) char *argv[],__attribute__((unused)) char *envp[])
{
}

extern "C" void _M2_mcStack_finish (__attribute__((unused)) int argc,__attribute__((unused)) char *argv[],__attribute__((unused)) char *envp[])
{
}
