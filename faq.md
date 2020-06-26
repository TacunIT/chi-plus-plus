---
layout:     pagina
class:      faq
title:      Domande frequenti
permalink:  /faq/
---

<section class="elenco faq">
    {% for post in site.categories.faq %}
        <div class="faq">
            <h3>{{ post.title }}</h3>
            {{ post.content }}
        </div>
    {% endfor %}
</section>
