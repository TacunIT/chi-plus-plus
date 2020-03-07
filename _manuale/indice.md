---
layout: manuale
title: C'hi++ - Il senso della Vita è il debug
h2: Indice
class: indice
precedente: dedica.html
seguente: premessa.html
permalink: /manuale/indice
no-index: true
---

<a class="logo" href="/manuale/"><img class="logo" alt="C'hi++" title="C'hi plus plus" src="/assets/img/chi-plus-plus.png"></a>
<section class="indice">
    {% for pagina in site.manuale %}
        {% if pagina.no-index == null %}
        <h3>
            <a href="{{ pagina.url }}">
                {{ pagina.h2 }}
            </a>
        </h3>
        {% endif %}
    {% endfor %}
    <h3 class="home">
        <a href="/" title="Torna alla home-page"><i class="fa fa-home fa-2x" aria-hidden="true"></i></a>
    </h3>
</section>
