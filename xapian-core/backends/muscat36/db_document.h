/* db_document.h: C++ class definition for DB access routines
 *
 * ----START-LICENCE----
 * Copyright 1999,2000,2001 BrightStation PLC
 * Copyright 2002 Ananova Ltd
 * Copyright 2003 Olly Betts
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA
 * -----END-LICENCE-----
 */

#ifndef OM_HGUARD_DB_DOCUMENT_H
#define OM_HGUARD_DB_DOCUMENT_H

#include "document.h"
struct record;

class DBDatabase;

/// A document from a DA format database
class DBDocument : public Xapian::Document::Internal {
    friend class DBDatabase;
    private:
	const DBDatabase * database;
	mutable struct record * rec;
	bool heavy_duty;

	DBDocument(const DBDatabase * database_, Xapian::docid did_,
		   bool heavy_duty_, bool lazy);

	// Stop copying
	DBDocument(const DBDocument &);
	void operator = (const DBDocument &);
    public:
	~DBDocument();

	string do_get_value(Xapian::valueno valueid) const;
	map<Xapian::valueno, string> do_get_all_values() const;
	string do_get_data() const;
};

#endif /* OM_HGUARD_DB_DOCUMENT_H */
