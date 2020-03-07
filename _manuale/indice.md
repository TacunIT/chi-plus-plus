---
layout: manuale
title: C'hi++ - Il senso della Vita è il debug
h2: Indice
class: indice
precedente: dedica.html
seguente: premessa.html
permalink: /manuale/indice
---

<section class="indice">
    {% for pagina in site.manuale %}
      <h3>
        <a href="{{ pagina.url }}">
            {{ pagina.h2 }}
        </a>
      </h3>
    {% endfor %}
    <h3 class="home">
        <a href="/" title="Torna alla home-page"><i class="fa fa-home fa-2x" aria-hidden="true"></i></a>
    </h3>
</section>
