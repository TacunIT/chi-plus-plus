CREATE FUNCTION utente_insert (
  _id_classe INTEGER
, _id_gruppo INTEGER
, _username  VARCHAR(255)
, _cognome   VARCHAR(80)
, _nome      VARCHAR(80)
)
RETURNS INTEGER DETERMINISTIC
BEGIN
    DECLARE _id    INTEGER DEFAULT -1;
    DECLARE _count INTEGER DEFAULT 0;

    SELECT count(*) INTO _count FROM classe WHERE (id = _id_classe);
    IF _count = 0 THEN
        RETURN -2;
    END IF;

    SELECT count(*) INTO _count FROM gruppo WHERE (id = _id_gruppo);
    IF _count = 0 THEN
        RETURN -3;
    END IF;

    IF (_username IS NULL) OR (_username = '') THEN
        RETURN -4;
    END IF;
    
    IF (_cognome IS NULL) OR (_cognome = '') THEN
        RETURN -5;
    END IF;

    IF (_nome IS NULL) OR (_nome = '') THEN
        RETURN -6;
    END IF;

    ...
