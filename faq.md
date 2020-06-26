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
            {% if post.layout == "" %}
                {{ post.content }}
            {% else %}
                {{ post.excerpt }}
            {% endif %}
            </div>
    {% endfor %}
</section>
