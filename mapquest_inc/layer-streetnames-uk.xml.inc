<Style name="shield-text">
	<!--motorway shields-->
	<Rule>
		<Filter>[highway] = 'motorway' and [length] gt 1 and [length] &lt; 9</Filter>
		&maxscale_zoom7;
		&minscale_zoom13;
		<ShieldSymbolizer fontset-name="bold-fonts" size="10" fill="#fff" placement="line" file="&symbols;/shield_mot_uk[length].svg" minimum-distance="30" spacing="750">[ref]</ShieldSymbolizer>
	</Rule>
	<Rule>
		<Filter>[highway] = 'motorway' and [length] gt 1 and [length] &lt; 9</Filter>
		&maxscale_zoom14;
		&minscale_zoom18;
		<ShieldSymbolizer fontset-name="bold-fonts" size="10" fill="#fff" placement="line" file="&symbols;/shield_mot_uk[length].svg" minimum-distance="50" spacing="750">[ref]</ShieldSymbolizer>
	</Rule>
	<!--trunk shields-->
	<Rule>
		<Filter>[highway] = 'trunk' and [length] gt 1 and [length] &lt; 9</Filter>
		&maxscale_zoom10;
		&minscale_zoom13;
		<ShieldSymbolizer fontset-name="bold-fonts" size="10" fill="#f9ee7c" placement="line" file="&symbols;/shield_trk_uk[length].svg"  minimum-distance="30" spacing="750">[ref]</ShieldSymbolizer>
	</Rule>
	<Rule>
		<Filter>[highway] = 'trunk' and [length] gt 1 and [length] &lt; 9</Filter>
		&maxscale_zoom14;
		&minscale_zoom18;
		<ShieldSymbolizer fontset-name="bold-fonts" size="10" fill="#f9ee7c" placement="line" file="&symbols;/shield_trk_uk[length].svg"  minimum-distance="50" spacing="750">[ref]</ShieldSymbolizer>
	</Rule>
	<!--primary shields-->
	<Rule>
		<Filter>[highway] = 'primary' and [length] gt 1 and [length] &lt; 9</Filter>
		&maxscale_zoom12;
		&minscale_zoom13;
		<ShieldSymbolizer fontset-name="bold-fonts" size="10" fill="#a64263" placement="line" file="&symbols;/shield_pri_uk[length].svg" minimum-distance="30" spacing="750">[ref]</ShieldSymbolizer>
	</Rule>
	<Rule>
		<Filter>[highway] = 'primary' and [length] gt 1 and [length] &lt; 9</Filter>
		&maxscale_zoom14;
		&minscale_zoom18;
		<ShieldSymbolizer fontset-name="bold-fonts" size="10" fill="#a64263" placement="line" file="&symbols;/shield_pri_uk[length].svg" minimum-distance="50" spacing="750">[ref]</ShieldSymbolizer>
	</Rule>
	<!--secondary shields-->
	<Rule>
		<Filter>[highway] = 'secondary' and [length] gt 1 and [length] &lt; 9</Filter>
		&maxscale_zoom10;
		&minscale_zoom13;
		<ShieldSymbolizer fontset-name="bold-fonts" size="10" fill="#000" placement="line" file="&symbols;/shield_sec_uk[length].svg" minimum-distance="30" spacing="750">[ref]</ShieldSymbolizer>
	</Rule>
	<Rule>
		<Filter>[highway] = 'secondary' and [length] gt 1 and [length] &lt; 9</Filter>
		&maxscale_zoom14;
		&minscale_zoom18;
		<ShieldSymbolizer fontset-name="bold-fonts" size="10" fill="#000" placement="line" file="&symbols;/shield_sec_uk[length].svg" minimum-distance="50" spacing="750">[ref]</ShieldSymbolizer>
	</Rule>
</Style>
<Style name="street-text">
  
  <!--motorway text-->
  <Rule>
    <Filter>[highway] = 'motorway'</Filter>
    &maxscale_zoom12;
    <TextSymbolizer fontset-name="bold-fonts" size="12" fill="#2b2b2b" halo-fill="rgba(255,255,255,0.25)" halo-radius="2" placement="line" max-char-angle-delta="40" text-transform="uppercase" avoid-edges="true">[name]</TextSymbolizer>
  </Rule>
  <!--trunk/primary text-->
  <Rule>
    <Filter>[highway] = 'trunk' or [highway] = 'primary'</Filter>
    &maxscale_zoom12;
    <TextSymbolizer fontset-name="book-fonts" size="12" fill="#2b2b2b" halo-fill="rgba(255,255,255,0.25)" halo-radius="2" placement="line" max-char-angle-delta="40" avoid-edges="true">[name]</TextSymbolizer>
  </Rule>
  <!--secondary text-->
  <Rule>
    <Filter>[highway] = 'secondary' or [highway] = 'proposed' or [highway]='construction'</Filter>
    &maxscale_zoom12;
    <TextSymbolizer fontset-name="book-fonts" size="12" fill="#2b2b2b" halo-fill="rgba(255,255,255,0.25)" halo-radius="2" placement="line" max-char-angle-delta="40" avoid-edges="true">[name]</TextSymbolizer>
  </Rule>
  <!--tertiary text-->
  <Rule>
    <Filter>[highway] = 'tertiary' or [highway] = 'unclassified' or [highway] = 'residential'</Filter>
    &maxscale_zoom16;
    &minscale_zoom17;
    <TextSymbolizer fontset-name="book-fonts" size="11" fill="#2b2b2b" halo-fill="rgba(255,255,255,0.25)" halo-radius="2" placement="line" max-char-angle-delta="40" avoid-edges="true">[name]</TextSymbolizer>
  </Rule>
  <Rule>
    <Filter>[highway] = 'tertiary' or [highway] = 'unclassified' or [highway] = 'residential'</Filter>
    &maxscale_zoom18;
    <TextSymbolizer fontset-name="book-fonts" size="12" fill="#2b2b2b" halo-fill="rgba(255,255,255,0.25)" halo-radius="2" placement="line" max-char-angle-delta="40" avoid-edges="true">[name]</TextSymbolizer>
  </Rule>
</Style>

<Layer name="shield-text" status="on" srs="&osm2pgsql_projection;">
  <StyleName>shield-text</StyleName>
  <Datasource>
    <Parameter name="table">
      (select way,highway,
      case when name ilike ref then null else name end as name,
      regexp_replace(regexp_replace(ref,E'\\s*[;,]\\s*',E'/'),E'\\s*[;,].*',E'') as ref,
      char_length(regexp_replace(regexp_replace(ref,E'\\s*[;,]\\s*',E'/'),E'\\s*[;,].*',E'')) as length
      from &prefix;_roads
      where highway in ('motorway', 'trunk', 'primary', 'secondary')
      and (name is not null or ref is not null)
      ) as roads
    </Parameter>
    &datasource-settings;
  </Datasource>
</Layer>
<Layer name="street-text" status="on" srs="&osm2pgsql_projection;">
  <StyleName>street-text</StyleName>
  <Datasource>
    <Parameter name="table">
      (select way,highway,
      case when name ilike ref then null else name end as name,
      case when bridge in ('yes','true','1') then 'yes'::text else bridge end as bridge
      from &prefix;_line
      where highway in ('motorway','trunk','primary','secondary','tertiary','unclassified','residential')
      and (name is not null or ref is not null)
      ) as roads
    </Parameter>
    &datasource-settings;
  </Datasource>
</Layer>
