/**************************************************************************

    util.h

    Copyright (C) 1998 Andrew Veliath

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

    $Id$

***************************************************************************/
#ifndef __UTIL_H
#define __UTIL_H

#if defined(HAVE_STDDEF_H)
#  include <stddef.h>
#endif
#if defined(HAVE_WCHAR_H)
#  include <wchar.h>
#elif defined(HAVE_WCSTR_H)
#  include <wcstr.h>
#endif

#include <glib.h>

#ifndef HAVE_STRDUP
#define strdup		__strdup
extern char *		strdup(const char *s);
#endif

extern void		yyerror(const char *s);
extern void		yyerrorl(const char *s, int ofs);
extern void		yywarning(int level, const char *s);
extern void		yywarningl(int level, const char *s, int ofs);
extern void		yyerrorv(const char *fmt, ...);
extern void		yyerrorlv(const char *fmt, int ofs, ...);
extern void		yywarningv(int level, const char *fmt, ...);
extern void		yywarninglv(int level, const char *fmt, int ofs, ...);

#ifndef HAVE_CPP_PIPE_STDIN
extern char *		__IDL_tmp_filename;
#endif
extern const char *	__IDL_real_filename;
extern char *		__IDL_cur_filename;
extern int		__IDL_cur_line;
extern int		__IDL_prev_token_line;
extern int		__IDL_cur_token_line;

#endif /* __UTIL_H */
