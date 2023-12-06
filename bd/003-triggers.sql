CREATE OR REPLACE FUNCTION AUMENTARNUMAULAS()
RETURNS trigger
AS $$
    begin
        update "ALUNO" 
		set "NUMAULAS" = "NUMAULAS" + 1 
		where "CHAVEALU" = new."CHAVEALU";
        return NEW;
    end;
$$ LANGUAGE plpgsql;
 
CREATE TRIGGER TAI0_PRESENCA
AFTER INSERT ON "PRESENCA"
    FOR EACH ROW EXECUTE PROCEDURE AUMENTARNUMAULAS();

/* Alterando a versão para 3 */
SELECT setval('public."VERSAOBD"', 3, true);

commit work;