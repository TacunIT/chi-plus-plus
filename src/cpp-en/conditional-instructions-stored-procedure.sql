CREATE FUNCTION user_insert (
  _class_id  INTEGER
, _group_id  INTEGER
, _username  VARCHAR(255)
, _lastname  VARCHAR(80)
, _firstname VARCHAR(80)
)
RETURNS INTEGER DETERMINISTIC
BEGIN
    DECLARE _id    INTEGER DEFAULT -1;
    DECLARE _count INTEGER DEFAULT 0;

    SELECT count(*) INTO _count FROM class WHERE (id = _class_id);
    IF _count = 0 THEN
        RETURN -2;
    END IF;

    SELECT count(*) INTO _count FROM user_group WHERE (id = _group_id);
    IF _count = 0 THEN
        RETURN -3;
    END IF;

    IF (_username IS NULL) OR (_username = '') THEN
        RETURN -4;
    END IF;

    IF (_lastname IS NULL) OR (_lastname = '') THEN
        RETURN -5;
    END IF;

    IF (_firstname IS NULL) OR (_firstname = '') THEN
        RETURN -6;
    END IF;

    ...
