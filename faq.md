---
layout:     default
class:      [pagina. faq]
title:      Domande frequenti
permalink:  /faq/
---

<h2>{{ page.title }}</h2>
{% for post in site.categories.faq %}
{% if post.status == "pubblicato" %}
<div class="faq">
<h3><a href="{{ post.url }}">{{ post.title }}</a></h3>
{{ post.content }}
</div>
{% endif %}
{% endfor %}
