-- Database: PaivaTeam

-- DROP DATABASE IF EXISTS "PaivaTeam";

CREATE DATABASE "PaivaTeam"
    WITH
    OWNER = postgres
    ENCODING = 'UTF8'
    LC_COLLATE = 'Portuguese_Brazil.1252'
    LC_CTYPE = 'Portuguese_Brazil.1252'
    TABLESPACE = pg_default
    CONNECTION LIMIT = -1
    IS_TEMPLATE = False;
	
commit work;
	
-- Table: public.PESSOA

-- DROP TABLE IF EXISTS public."PESSOA";

CREATE TABLE IF NOT EXISTS public."PESSOA"
(
    "CHAVEPES" bigint NOT NULL GENERATED ALWAYS AS IDENTITY ( INCREMENT 1 START 1 MINVALUE 1 MAXVALUE 9223372036854775807 CACHE 1 ),
    "APELIDO" character varying(15) COLLATE pg_catalog."default",
    "DTNASCIMENTO" date,
    "CPF" character(14) COLLATE pg_catalog."default",
    "RG" character(14) COLLATE pg_catalog."default",
    "SEXO" "char" NOT NULL,
    "NOME" character varying(40) COLLATE pg_catalog."default",
    CONSTRAINT "CHAVEPES_pkey" PRIMARY KEY ("CHAVEPES")
)
	
commit work;

TABLESPACE pg_default;

ALTER TABLE IF EXISTS public."PESSOA"
    OWNER to postgres;

COMMENT ON COLUMN public."PESSOA"."DTNASCIMENTO"
    IS 'Data de Nascimento';

COMMENT ON COLUMN public."PESSOA"."SEXO"
    IS 'M - Masculino
F - Feminino
I - Indefinido';

-- Table: public.MODALIDADE

-- DROP TABLE IF EXISTS public."MODALIDADE";

CREATE TABLE IF NOT EXISTS public."MODALIDADE"
(
    "CHAVEMOD" bigint NOT NULL GENERATED ALWAYS AS IDENTITY ( INCREMENT 1 START 1 MINVALUE 1 MAXVALUE 9223372036854775807 CACHE 1 ),
    "CHAVEPES" bigint NOT NULL,
    "NOME" character varying(30) COLLATE pg_catalog."default",
    CONSTRAINT "CHAVEMOD_pkey" PRIMARY KEY ("CHAVEMOD"),
    CONSTRAINT "fk_MODALIDADE_PESSOA" FOREIGN KEY ("CHAVEPES")
        REFERENCES public."PESSOA" ("CHAVEPES") MATCH SIMPLE
        ON UPDATE NO ACTION
        ON DELETE NO ACTION
)
	
commit work;

TABLESPACE pg_default;

ALTER TABLE IF EXISTS public."MODALIDADE"
    OWNER to postgres;

-- Table: public.GRADUACAO

-- DROP TABLE IF EXISTS public."GRADUACAO";

CREATE TABLE IF NOT EXISTS public."GRADUACAO"
(
    "CHAVEGRD" bigint NOT NULL GENERATED ALWAYS AS IDENTITY ( INCREMENT 1 START 1 MINVALUE 1 MAXVALUE 9223372036854775807 CACHE 1 ),
    "CHAVEMOD" bigint NOT NULL,
    "NOME" character varying(30) COLLATE pg_catalog."default" NOT NULL,
    "ORDEM" bigint NOT NULL,
    "MINAULAS" integer NOT NULL,
    CONSTRAINT "CHAVEGRD_pkey" PRIMARY KEY ("CHAVEGRD"),
    CONSTRAINT "fk_GRADUACAO_MODALIDADE" FOREIGN KEY ("CHAVEMOD")
        REFERENCES public."MODALIDADE" ("CHAVEMOD") MATCH SIMPLE
        ON UPDATE NO ACTION
        ON DELETE NO ACTION
)
	
commit work;

TABLESPACE pg_default;

ALTER TABLE IF EXISTS public."GRADUACAO"
    OWNER to postgres;

COMMENT ON COLUMN public."GRADUACAO"."ORDEM"
    IS 'Ordem da Graduação Ex: 1 - Branca, 2 - Cinza';

COMMENT ON COLUMN public."GRADUACAO"."MINAULAS"
    IS 'Mínimo de aulas para Graduar';	
	
-- Table: public.ALUNO

-- DROP TABLE IF EXISTS public."ALUNO";

CREATE TABLE IF NOT EXISTS public."ALUNO"
(
    "CHAVEALU" bigint NOT NULL GENERATED ALWAYS AS IDENTITY ( INCREMENT 1 START 1 MINVALUE 1 MAXVALUE 9223372036854775807 CACHE 1 ),
    "CHAVEPES" bigint NOT NULL,
    "CHAVEGRD" bigint NOT NULL,
    "NUMAULAS" integer NOT NULL DEFAULT 0,
    CONSTRAINT "CHAVEALU_pkey" PRIMARY KEY ("CHAVEALU"),
    CONSTRAINT "fk_ALUNO_GRADUACAO" FOREIGN KEY ("CHAVEGRD")
        REFERENCES public."GRADUACAO" ("CHAVEGRD") MATCH SIMPLE
        ON UPDATE NO ACTION
        ON DELETE NO ACTION,
    CONSTRAINT "fk_ALUNO_PESSOA" FOREIGN KEY ("CHAVEPES")
        REFERENCES public."PESSOA" ("CHAVEPES") MATCH SIMPLE
        ON UPDATE NO ACTION
        ON DELETE NO ACTION
)
	
commit work;

TABLESPACE pg_default;

ALTER TABLE IF EXISTS public."ALUNO"
    OWNER to postgres;

COMMENT ON COLUMN public."ALUNO"."NUMAULAS"
    IS 'Quantidade de aulas parcial, utilizada para mostrar se já está apto a graduar';
	
-- Table: public.CADPENDENTE

-- DROP TABLE IF EXISTS public."CADPENDENTE";

CREATE TABLE IF NOT EXISTS public."CADPENDENTE"
(
    "CHAVECAD" bigint NOT NULL GENERATED ALWAYS AS IDENTITY ( INCREMENT 1 START 1 MINVALUE 1 MAXVALUE 9223372036854775807 CACHE 1 ),
    "NOME" character varying(40) COLLATE pg_catalog."default",
    "APELIDO" character varying(15) COLLATE pg_catalog."default",
    "DTNASCIMENTO" date,
    "CPF" character(14) COLLATE pg_catalog."default",
    "RG" character(14) COLLATE pg_catalog."default",
    "SEXO" "char" NOT NULL DEFAULT 'I'::"char",
    "LOGIN" character varying(30) COLLATE pg_catalog."default",
    "SENHA" character varying(15) COLLATE pg_catalog."default",
    "TIPO" "char" NOT NULL DEFAULT 'A'::"char",
    CONSTRAINT "CHAVECAD_pkey" PRIMARY KEY ("CHAVECAD")
)
	
commit work;

TABLESPACE pg_default;

ALTER TABLE IF EXISTS public."CADPENDENTE"
    OWNER to postgres;
	
-- Table: public.MENSALIDADE

-- DROP TABLE IF EXISTS public."MENSALIDADE";

CREATE TABLE IF NOT EXISTS public."MENSALIDADE"
(
    "CHAVEMEN" bigint NOT NULL GENERATED ALWAYS AS IDENTITY ( INCREMENT 1 START 1 MINVALUE 1 MAXVALUE 9223372036854775807 CACHE 1 ),
    "CHAVEPES" bigint NOT NULL,
    "VALOR" double precision NOT NULL,
    CONSTRAINT "CHAVEMEN_pkey" PRIMARY KEY ("CHAVEMEN"),
    CONSTRAINT "fk_MENSALIDADE_PESSOA" FOREIGN KEY ("CHAVEPES")
        REFERENCES public."PESSOA" ("CHAVEPES") MATCH SIMPLE
        ON UPDATE NO ACTION
        ON DELETE NO ACTION
)
	
commit work;

TABLESPACE pg_default;

ALTER TABLE IF EXISTS public."MENSALIDADE"
    OWNER to postgres;
	
-- Table: public.PAGAMENTOS

-- DROP TABLE IF EXISTS public."PAGAMENTOS";

CREATE TABLE IF NOT EXISTS public."PAGAMENTOS"
(
    "CHAVEPAG" bigint NOT NULL GENERATED ALWAYS AS IDENTITY ( INCREMENT 1 START 1 MINVALUE 1 MAXVALUE 9223372036854775807 CACHE 1 ),
    "CHAVEPES" bigint NOT NULL,
    "DTPAGAMENTO" date NOT NULL,
    "EFETIVADO" boolean NOT NULL DEFAULT false,
    CONSTRAINT "CHAVEPAG_pkey" PRIMARY KEY ("CHAVEPAG"),
    CONSTRAINT "fk_PAGAMENTO_PESSOA" FOREIGN KEY ("CHAVEPES")
        REFERENCES public."PESSOA" ("CHAVEPES") MATCH SIMPLE
        ON UPDATE NO ACTION
        ON DELETE NO ACTION
)
	
commit work;

TABLESPACE pg_default;

ALTER TABLE IF EXISTS public."PAGAMENTOS"
    OWNER to postgres;

-- Table: public.TURMA

-- DROP TABLE IF EXISTS public."TURMA";

CREATE TABLE IF NOT EXISTS public."TURMA"
(
    "CHAVETUR" bigint NOT NULL GENERATED ALWAYS AS IDENTITY ( INCREMENT 1 START 1 MINVALUE 1 MAXVALUE 9223372036854775807 CACHE 1 ),
    "CHAVEPES" bigint NOT NULL,
    "CHAVEMOD" bigint NOT NULL,
    "HRINICIO" time without time zone NOT NULL,
    "HRFIM" time without time zone NOT NULL,
    "DIASSEMANA" character varying(7) COLLATE pg_catalog."default" NOT NULL,
    CONSTRAINT "CHAVETUR_pkey" PRIMARY KEY ("CHAVETUR"),
    CONSTRAINT "fk_TURMA_MODALIDADE" FOREIGN KEY ("CHAVEMOD")
        REFERENCES public."MODALIDADE" ("CHAVEMOD") MATCH SIMPLE
        ON UPDATE NO ACTION
        ON DELETE NO ACTION,
    CONSTRAINT "fk_TURMA_PESSOA" FOREIGN KEY ("CHAVEPES")
        REFERENCES public."PESSOA" ("CHAVEPES") MATCH SIMPLE
        ON UPDATE NO ACTION
        ON DELETE NO ACTION
)
	
commit work;

TABLESPACE pg_default;

ALTER TABLE IF EXISTS public."TURMA"
    OWNER to postgres;

COMMENT ON COLUMN public."TURMA"."CHAVEPES"
    IS 'Professor relacionado';

COMMENT ON COLUMN public."TURMA"."HRINICIO"
    IS 'Hora de início da aula';

COMMENT ON COLUMN public."TURMA"."HRFIM"
    IS 'Hora de término da aula';

COMMENT ON COLUMN public."TURMA"."DIASSEMANA"
    IS 'String com os dias de aula
1 - Dom, 2- Seg, 3-Ter... 7-Sab
Escrita na forma: "3, 5" (Segunda e quinta)';

-- Table: public.USUARIO

-- DROP TABLE IF EXISTS public."USUARIO";

CREATE TABLE IF NOT EXISTS public."USUARIO"
(
    "CHAVEUSU" bigint NOT NULL GENERATED ALWAYS AS IDENTITY ( INCREMENT 1 START 0 MINVALUE 0 MAXVALUE 9223372036854775807 CACHE 1 ),
    "CHAVEPES" bigint NOT NULL,
    "LOGIN" character varying(30) COLLATE pg_catalog."default",
    "SENHA" character varying(15) COLLATE pg_catalog."default",
    "TIPO" "char",
    CONSTRAINT "USUARIO_pkey" PRIMARY KEY ("CHAVEUSU"),
    CONSTRAINT "fk_USUARIO_PESSOA" FOREIGN KEY ("CHAVEPES")
        REFERENCES public."PESSOA" ("CHAVEPES") MATCH SIMPLE
        ON UPDATE NO ACTION
        ON DELETE NO ACTION
        NOT VALID
)
	
commit work;

TABLESPACE pg_default;

ALTER TABLE IF EXISTS public."USUARIO"
    OWNER to postgres;

COMMENT ON COLUMN public."USUARIO"."LOGIN"
    IS 'Provavelmente Email';

COMMENT ON COLUMN public."USUARIO"."SENHA"
    IS 'Senha Criptografada';

COMMENT ON COLUMN public."USUARIO"."TIPO"
    IS 'Flag de Acesso
A - Administrador
P - Professor
C - Cliente (Alunos, Praticantes)
';
-- Index: fki_fk_USUARIO_PESSOA

-- DROP INDEX IF EXISTS public."fki_fk_USUARIO_PESSOA";

CREATE INDEX IF NOT EXISTS "fki_fk_USUARIO_PESSOA"
    ON public."USUARIO" USING btree
    ("CHAVEPES" ASC NULLS LAST)
    TABLESPACE pg_default;
	
-- Table: public.PRESENCA

-- DROP TABLE IF EXISTS public."PRESENCA";

CREATE TABLE IF NOT EXISTS public."PRESENCA"
(
    "CHAVEPRE" bigint NOT NULL GENERATED ALWAYS AS IDENTITY ( INCREMENT 1 START 1 MINVALUE 1 MAXVALUE 9223372036854775807 CACHE 1 ),
    "CHAVEPES" bigint NOT NULL,
    "CHAVETUR" bigint NOT NULL,
    CONSTRAINT "CHAVEPRE_pkey" PRIMARY KEY ("CHAVEPRE"),
    CONSTRAINT "fk_PRESENCA_PESSOA" FOREIGN KEY ("CHAVEPES")
        REFERENCES public."PESSOA" ("CHAVEPES") MATCH SIMPLE
        ON UPDATE NO ACTION
        ON DELETE NO ACTION,
    CONSTRAINT "fk_PRESENCA_TURMA" FOREIGN KEY ("CHAVETUR")
        REFERENCES public."TURMA" ("CHAVETUR") MATCH SIMPLE
        ON UPDATE NO ACTION
        ON DELETE NO ACTION
)
	
commit work;

TABLESPACE pg_default;

ALTER TABLE IF EXISTS public."PRESENCA"
    OWNER to postgres;
	
CREATE SEQUENCE public."VERSAOBD"
    INCREMENT 1
    START 0
    MINVALUE 0;
	
commit work;

ALTER SEQUENCE public."VERSAOBD"
    OWNER TO postgres;

/* Alterando a versão para 1 */
SELECT setval('public."VERSAOBD"', 1, true);

commit work;