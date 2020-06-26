---
layout:     faq
class:      faq
title:      Domande frequenti
permalink:  /faq/
---

<section class="elenco faq">
    {% for post in site.categories.faq %}
    {% if post.status == "pubblicato" %}
    <div class="faq">
    <h3>{{ post.title }}</h3>
    {{ post.content }}
    </div>
    {% endif %}
    {% endfor %}
</section>
