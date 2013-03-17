// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "dogen/database/odb/primary_key_2-odb.hxx"

#include <cassert>
#include <cstring>  // std::memcpy

#include <odb/schema-catalog-impl.hxx>
#include <odb/details/shared-ptr.hxx>

#include <odb/pgsql/traits.hxx>
#include <odb/pgsql/database.hxx>
#include <odb/pgsql/transaction.hxx>
#include <odb/pgsql/connection.hxx>
#include <odb/pgsql/statement.hxx>
#include <odb/pgsql/statement-cache.hxx>
#include <odb/pgsql/simple-object-statements.hxx>
#include <odb/pgsql/container-statements.hxx>
#include <odb/pgsql/exceptions.hxx>
#include <odb/pgsql/simple-object-result.hxx>

namespace odb
{
  // primary_key_2
  //

  const char access::object_traits< ::dogen::database::primary_key_2 >::
  persist_statement_name[] = "dogen_database_primary_key_2_persist";

  const char access::object_traits< ::dogen::database::primary_key_2 >::
  find_statement_name[] = "dogen_database_primary_key_2_find";

  const char access::object_traits< ::dogen::database::primary_key_2 >::
  erase_statement_name[] = "dogen_database_primary_key_2_erase";

  const char access::object_traits< ::dogen::database::primary_key_2 >::
  query_statement_name[] = "dogen_database_primary_key_2_query";

  const char access::object_traits< ::dogen::database::primary_key_2 >::
  erase_query_statement_name[] = "dogen_database_primary_key_2_erase_query";

  const unsigned int access::object_traits< ::dogen::database::primary_key_2 >::
  persist_statement_types[] =
  {
    pgsql::int4_oid
  };

  const unsigned int access::object_traits< ::dogen::database::primary_key_2 >::
  find_statement_types[] =
  {
    pgsql::int4_oid
  };

  access::object_traits< ::dogen::database::primary_key_2 >::id_type
  access::object_traits< ::dogen::database::primary_key_2 >::
  id (const image_type& i)
  {
    pgsql::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    id_type id;
    {
      pgsql::value_traits<
          unsigned int,
          pgsql::id_integer >::set_value (
        id,
        i.prop_0_value,
        i.prop_0_null);
    }

    return id;
  }

  bool access::object_traits< ::dogen::database::primary_key_2 >::
  grow (image_type& i, bool* t)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (t);

    bool grew (false);

    // prop_0_
    //
    t[0UL] = 0;

    return grew;
  }

  void access::object_traits< ::dogen::database::primary_key_2 >::
  bind (pgsql::bind* b,
        image_type& i,
        pgsql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace pgsql;

    std::size_t n (0);

    // prop_0_
    //
    if (sk != statement_update)
    {
      b[n].type = pgsql::bind::integer;
      b[n].buffer = &i.prop_0_value;
      b[n].is_null = &i.prop_0_null;
      n++;
    }
  }

  void access::object_traits< ::dogen::database::primary_key_2 >::
  bind (pgsql::bind* b, id_image_type& i)
  {
    std::size_t n (0);
    b[n].type = pgsql::bind::integer;
    b[n].buffer = &i.id_value;
    b[n].is_null = &i.id_null;
  }

  bool access::object_traits< ::dogen::database::primary_key_2 >::
  init (image_type& i, const object_type& o, pgsql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace pgsql;

    bool grew (false);

    // prop_0_
    //
    if (sk == statement_insert)
    {
      unsigned int const& v =
        o.prop_0 ();

      bool is_null (false);
      pgsql::value_traits<
          unsigned int,
          pgsql::id_integer >::set_image (
        i.prop_0_value, is_null, v);
      i.prop_0_null = is_null;
    }

    return grew;
  }

  void access::object_traits< ::dogen::database::primary_key_2 >::
  init (object_type& o, const image_type& i, database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // prop_0_
    //
    {
      unsigned int v;

      pgsql::value_traits<
          unsigned int,
          pgsql::id_integer >::set_value (
        v,
        i.prop_0_value,
        i.prop_0_null);

      o.prop_0 (v);
    }
  }

  void access::object_traits< ::dogen::database::primary_key_2 >::
  init (id_image_type& i, const id_type& id)
  {
    {
      bool is_null (false);
      pgsql::value_traits<
          unsigned int,
          pgsql::id_integer >::set_image (
        i.id_value, is_null, id);
      i.id_null = is_null;
    }
  }

  struct access::object_traits< ::dogen::database::primary_key_2 >::container_statement_cache_type
  {
    container_statement_cache_type (pgsql::connection&)
    {
    }
  };

  const char access::object_traits< ::dogen::database::primary_key_2 >::persist_statement[] =
  "INSERT INTO \"kitanda\".\"primary_key_2\" ("
  "\"prop_0\")"
  " VALUES ($1)";

  const char access::object_traits< ::dogen::database::primary_key_2 >::find_statement[] =
  "SELECT "
  "\"kitanda\".\"primary_key_2\".\"prop_0\""
  " FROM \"kitanda\".\"primary_key_2\""
  " WHERE \"kitanda\".\"primary_key_2\".\"prop_0\"=$1";

  const char access::object_traits< ::dogen::database::primary_key_2 >::erase_statement[] =
  "DELETE FROM \"kitanda\".\"primary_key_2\""
  " WHERE \"prop_0\"=$1";

  const char access::object_traits< ::dogen::database::primary_key_2 >::query_statement[] =
  "SELECT "
  "\"kitanda\".\"primary_key_2\".\"prop_0\""
  " FROM \"kitanda\".\"primary_key_2\""
  " ";

  const char access::object_traits< ::dogen::database::primary_key_2 >::erase_query_statement[] =
  "DELETE FROM \"kitanda\".\"primary_key_2\""
  " ";

  const char access::object_traits< ::dogen::database::primary_key_2 >::table_name[] =
  "\"kitanda\".\"primary_key_2\"";

  void access::object_traits< ::dogen::database::primary_key_2 >::
  persist (database& db, const object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace pgsql;

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    callback (db,
              obj,
              callback_event::pre_persist);

    image_type& im (sts.image ());
    binding& imb (sts.insert_image_binding ());

    if (init (im, obj, statement_insert))
      im.version++;

    if (im.version != sts.insert_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_insert);
      sts.insert_image_version (im.version);
      imb.version++;
    }

    insert_statement& st (sts.persist_statement ());
    if (!st.execute ())
      throw object_already_persistent ();

    callback (db,
              obj,
              callback_event::post_persist);
  }

  void access::object_traits< ::dogen::database::primary_key_2 >::
  update (database& db, const object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace pgsql;

    callback (db, obj, callback_event::pre_update);

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    const id_type& id (
      obj.prop_0 ());

    if (!find_ (sts, &id))
      throw object_not_persistent ();

    callback (db, obj, callback_event::post_update);
  }

  void access::object_traits< ::dogen::database::primary_key_2 >::
  erase (database& db, const id_type& id)
  {
    using namespace pgsql;

    ODB_POTENTIALLY_UNUSED (db);

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    id_image_type& i (sts.id_image ());
    init (i, id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    if (sts.erase_statement ().execute () != 1)
      throw object_not_persistent ();

    pointer_cache_traits::erase (db, id);
  }

  access::object_traits< ::dogen::database::primary_key_2 >::pointer_type
  access::object_traits< ::dogen::database::primary_key_2 >::
  find (database& db, const id_type& id)
  {
    using namespace pgsql;

    {
      pointer_type p (pointer_cache_traits::find (db, id));

      if (!pointer_traits::null_ptr (p))
        return p;
    }

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    if (l.locked ())
    {
      if (!find_ (sts, &id))
        return pointer_type ();
    }

    pointer_type p (
      access::object_factory<object_type, pointer_type>::create ());
    pointer_traits::guard pg (p);

    pointer_cache_traits::insert_guard ig (
      pointer_cache_traits::insert (db, id, p));

    object_type& obj (pointer_traits::get_ref (p));

    if (l.locked ())
    {
      select_statement& st (sts.find_statement ());
      ODB_POTENTIALLY_UNUSED (st);

      callback (db, obj, callback_event::pre_load);
      init (obj, sts.image (), &db);
      load_ (sts, obj);
      sts.load_delayed ();
      l.unlock ();
      callback (db, obj, callback_event::post_load);
    }
    else
      sts.delay_load (id, obj, ig.position ());

    ig.release ();
    pg.release ();
    return p;
  }

  bool access::object_traits< ::dogen::database::primary_key_2 >::
  find (database& db, const id_type& id, object_type& obj)
  {
    using namespace pgsql;

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    reference_cache_traits::insert_guard ig (
      reference_cache_traits::insert (db, id, obj));

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj);
    sts.load_delayed ();
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    ig.release ();
    return true;
  }

  bool access::object_traits< ::dogen::database::primary_key_2 >::
  reload (database& db, object_type& obj)
  {
    using namespace pgsql;

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    const id_type& id  (
      obj.prop_0 ());

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj);
    sts.load_delayed ();
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    return true;
  }

  bool access::object_traits< ::dogen::database::primary_key_2 >::
  find_ (statements_type& sts, const id_type* id)
  {
    using namespace pgsql;

    id_image_type& i (sts.id_image ());
    init (i, *id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    select_statement& st (sts.find_statement ());
    st.execute ();
    auto_result ar (st);
    select_statement::result r (st.fetch ());

    return r != select_statement::no_data;
  }

  result< access::object_traits< ::dogen::database::primary_key_2 >::object_type >
  access::object_traits< ::dogen::database::primary_key_2 >::
  query (database&, const query_base_type& q)
  {
    using namespace pgsql;
    using odb::details::shared;
    using odb::details::shared_ptr;

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());

    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    shared_ptr<select_statement> st (
      new (shared) select_statement (
        sts.connection (),
        query_statement_name,
        query_statement + q.clause (),
        q.parameter_types (),
        q.parameter_count (),
        q.parameters_binding (),
        imb));

    st->execute ();
    st->deallocate ();

    shared_ptr< odb::object_result_impl<object_type> > r (
      new (shared) pgsql::object_result_impl<object_type> (
        q, st, sts));

    return result<object_type> (r);
  }

  unsigned long long access::object_traits< ::dogen::database::primary_key_2 >::
  erase_query (database&, const query_base_type& q)
  {
    using namespace pgsql;

    pgsql::connection& conn (
      pgsql::transaction::current ().connection ());

    delete_statement st (
      conn,
      erase_query_statement_name,
      erase_query_statement + q.clause (),
      q.parameter_types (),
      q.parameter_count (),
      q.parameters_binding ());

    return st.execute ();
  }

  bool access::object_traits< ::dogen::database::primary_key_2 >::
  create_schema (database& db, unsigned short pass, bool drop)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (pass);
    ODB_POTENTIALLY_UNUSED (drop);

    if (drop)
    {
      switch (pass)
      {
        case 1:
        {
          db.execute ("DROP TABLE IF EXISTS \"kitanda\".\"primary_key_2\" CASCADE");
          return false;
        }
      }
    }
    else
    {
      switch (pass)
      {
        case 1:
        {
          db.execute ("CREATE TABLE \"kitanda\".\"primary_key_2\" (\n"
                      "  \"prop_0\" INTEGER NOT NULL PRIMARY KEY)");
          return false;
        }
      }
    }

    return false;
  }

  static const schema_catalog_entry
  schema_catalog_entry_dogen_database_primary_key_2_ (
    "",
    &access::object_traits< ::dogen::database::primary_key_2 >::create_schema);
}

#include <odb/post.hxx>
